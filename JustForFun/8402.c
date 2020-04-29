//
// Created by king on 8/9/18.
//
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define SIZE 4
uint32_t score;
uint8_t color_scheme = 0;

// 命令行缓冲切换
void setBufferedInput(bool enable);

// 初始化一个4×4的二维数组(矩阵)表示一个游戏的16个元素
void initMatrix(uint8_t matrix[SIZE][SIZE]);

void addRandom(uint8_t matrix[SIZE][SIZE]);

// 移动和旋转的方法
bool slideArray(uint8_t array[SIZE]);
void rotateMatrix(uint8_t (*matrix)[SIZE]);


uint8_t findTarget(const uint8_t *array, uint8_t i, uint8_t stop);

bool moveUp(uint8_t (*matrix)[SIZE]);
bool moveRight(uint8_t (*matrix)[SIZE]);
bool moveDown(uint8_t (*matrix)[SIZE]);
bool moveLeft(uint8_t (*matrix)[SIZE]);


bool hasEmpty(uint8_t (*matrix)[SIZE]);
bool hasPair(uint8_t (*matrix)[SIZE]);
bool canMove(uint8_t (*matrix)[SIZE]);
bool gameover(uint8_t (*matrix)[SIZE]);

void renderColor(uint8_t value, char *color, size_t lenght);
void printMatrix(uint8_t (*matrix)[SIZE]);

int test();

int main(int argc, char const *argv[]) {
    char c;
    bool success;
    uint8_t matrix[SIZE][SIZE];
    initMatrix(matrix);

    printMatrix(matrix);

    setBufferedInput(false);
    while (true) {
        c = (char) fgetc(stdin);
        if (c == -1) {
            fputs("\nError! Can't read keymatrix input!", stderr);
            break;
        }

        switch (c) {
            case 97:  // 'a' key
            case 104: // 'h' key
            case 68:  // '←' key
                success = moveLeft(matrix);
                break;
            case 100: // 'd'
            case 108: // 'l'
            case 67:  // '→'
                success = moveRight(matrix);
                break;
            case 119: // 'w'
            case 107: // 'k'
            case 65:  // '↑'
                success = moveUp(matrix);
                break;
            case 115: // 's'
            case 106: // 'j'
            case 66:  // '↓'
                success = moveDown(matrix);
                break;
            default:
                success = false;
        }

        if (success) {
            printMatrix(matrix);
            usleep(150000);
            addRandom(matrix);
            printMatrix(matrix);
            if (gameover(matrix)) {
                printf("         GAME OVER          \n");
                break;
            }
        }

        if (c=='q') {
            printf("        QUIT? (y/n)         \n");
            c=getchar();
            if (c=='y') {
                break;
            }
            printMatrix(matrix);
        }
        if (c=='r') {
            printf("       RESTART? (y/n)       \n");
            c=getchar();
            if (c=='y') {
                initMatrix(matrix);
            }
            printMatrix(matrix);
        }
    }

    setBufferedInput(true);
    fprintf(stdout, "\x1b[?25h\x1b[m");
//    test();
    return 0;
}

void renderColor(uint8_t value, char *color, size_t lenght)
{
    uint8_t original[][6] = {
            {207, 194, 182, 119, 110, 101},  // 0
            {238, 228, 218, 119, 110, 101},  // 2
            {237, 224, 200, 119, 110, 101},  // 4
            {237, 224, 200, 119, 110, 101},  // 4
            {242, 177, 121, 249, 246, 242},  // 8
            {245, 149, 99, 249, 246, 242},  // 16
            {246, 124, 95, 249, 246, 242},  // 32
            {246, 94, 59, 249, 246, 242},  // 64
            {237, 207, 114, 249, 246, 242},  // 128
            {237, 204, 97, 249, 246, 242},  // 256
            {237, 200, 80, 249, 246, 242},  // 512
            {237, 197, 63, 249, 246, 242},  // 1024
            {237, 194, 46, 249, 246, 242},  // 2048
    };

    uint8_t *background = original[value];
    uint8_t *foreground = original[value] + 3;

    snprintf(color, lenght, "\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm", *foreground, *(foreground+1), *(foreground + 2), *background, *(background+1), *(background + 2));

}

void printMatrix(uint8_t (*matrix)[4]) {
    int i, j;
    uint8_t temp, sl; // sl 意思是 space length,就是空格的长度或者说是个数
    char color[50], s[8], reset[] = "\x1b[m";
    fprintf(stdout, "\x1b[?25l\x1b[2J");
    fprintf(stdout, "\x1b[H");

    fprintf(stdout, "2048%19d pts\n\n", score);
//    fprintf(stdout, "\033[?25h\033[m");
//    system("clear");
    for (i = 0; i < SIZE; ++i) {
        printf("\n\n");
        for (j = 0; j < SIZE; ++j) {
            printf("\x1b[7C");
            printf("%s", "\x1b[2A");
            printf("%s", "\x1b[7D");
            temp = *(*(matrix + i) + j);
            renderColor(temp, color, 50);
            fprintf(stdout, "%s", color);
            fprintf(stdout, "       ");

            printf("\x1b[B");
            printf("%s", "\x1b[7D");
            if (temp == 0)
                fprintf(stdout, "   ·   ");
            else {
                snprintf(s, 8, "%u", 1 << temp);
                sl = (uint8_t) (7 - strlen(s));
                fprintf(stdout, "%*s%s%*s", sl / 2, "", s, sl - sl / 2, "");
            }

            printf("\x1b[B");
            printf("%s", "\x1b[7D");
            fprintf(stdout, "       ");
            fprintf(stdout, "%s", reset);
        }
        fprintf(stdout, "\n");
    }
    printf("\n");
    printf("        ←,↑,→,↓ or q        \n");
    fprintf(stdout, "\x1b[A");
}

void addRandom(uint8_t matrix[SIZE][SIZE]) {
    static bool initialized = false;
    uint8_t x, y;
    uint8_t r, len = 0;
    uint8_t n, list[SIZE * SIZE][2];

    if (!initialized) {
        srand((unsigned) time(NULL));
        initialized = true;
    }

    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
            if (matrix[x][y] == 0) {
                list[len][0] = x;
                list[len][1] = y;
                len++;
            }
        }
    }

    if (len > 0) {
        r = (uint8_t) rand() % len;
        x = list[r][0];
        y = list[r][1];
        n = (uint8_t) ((rand() % 10) / 7 + 1);
        matrix[x][y] = n;
    }
}

void initMatrix(uint8_t matrix[SIZE][SIZE]) {
    uint8_t x, y;
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
            matrix[x][y] = 0;
        }
    }
    addRandom(matrix);
    addRandom(matrix);
}

void setBufferedInput(bool enable) {
    static bool enabled = true;
    static struct termios old;
    struct termios new;

    if (enable && !enabled) {
        // restore the former settings
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
        // set the new state
        enabled = true;
    } else if (!enable && enabled) {
        // get the terminal settings for standard input
        tcgetattr(STDIN_FILENO, &new);
        // we want to keep the old setting to restore them at the end
        old = new;
        // disable canonical mode (buffered i/o) and local echo
        new.c_lflag &= (~ICANON & ~ECHO);
        // set the new settings immediately
        tcsetattr(STDIN_FILENO, TCSANOW, &new);
        // set the new state
        enabled = false;
    }
}

uint8_t findTarget(const uint8_t *array, uint8_t i, uint8_t stop) {
    uint8_t t;
    for (t = i - 1; t >= 0; --t) {
        if (array[t] != 0) {
            if (array[t] == array[i])
                return t;
            return t + 1;
        } else if (t == stop) {
            return t;
        }
    }
    printf("找不到的情况");
    return i;
}

bool slideArray(uint8_t array[SIZE]) {
//    for (int j = 0; j < SIZE; ++j) {
//        printf("%d", array[j]);
//    }
//    printf("\n");
    bool success = false;
    uint8_t i, t, stop; // i代表数组下标，他代表目标下标，stop代表停止位
    stop = 0;

    for (i = 1; i < SIZE; ++i) {
        t = findTarget(array, i, stop);
        if (i != t) {
            if (array[t] == 0)
                array[t] = array[i];
            else if (array[t] == array[i]) {
                ++array[t];
                score += (uint32_t) (1 << array[t]);
                stop = (uint8_t) (t + 1);
            }
            array[i] = 0;
            success = true;
        }
    }

    return success;
}

void rotateMatrix(uint8_t (*matrix)[SIZE])
{
    uint8_t i, j, temp;
    int count = 1;
    for (j = 0; j < SIZE / 2; ++j)
        for (i = j; i < (SIZE - 1 - j); ++i) {
//            printf("第%d次交换i=%d, j=%d;：\n", count++, i, j);
            temp = matrix[SIZE - 1 - i][j];
            matrix[SIZE - 1 - i][j] = matrix[SIZE - 1 - j][SIZE - 1 - i];
            matrix[SIZE - 1 - j][SIZE - 1 - i] = matrix[i][SIZE - 1 - j];
            matrix[i][SIZE - 1 - j] = matrix[j][i];
            matrix[j][i] = temp;
//            printMatrix(matrix);
        }
}

bool moveUp(uint8_t (*matrix)[SIZE]) {
    bool success = false;
    rotateMatrix(matrix);
    rotateMatrix(matrix);
    rotateMatrix(matrix);
    success = moveLeft(matrix);
    rotateMatrix(matrix);
    return success;
}

bool moveRight(uint8_t (*matrix)[SIZE]) {
    bool success = false;
    rotateMatrix(matrix);
    rotateMatrix(matrix);
    success = moveLeft(matrix);
    rotateMatrix(matrix);
    rotateMatrix(matrix);
    return success;
}

bool moveDown(uint8_t (*matrix)[SIZE]) {
    bool success = false;
    rotateMatrix(matrix);
    success = moveLeft(matrix);
    rotateMatrix(matrix);
    rotateMatrix(matrix);
    rotateMatrix(matrix);
    return success;
}

bool moveLeft(uint8_t (*matrix)[SIZE]) {
    bool success = false;
    int i;
    for (i = 0; i < SIZE; ++i) {
        success |= slideArray(*(matrix + i));
    }

    return success;
}

bool hasEmpty(uint8_t (*matrix)[SIZE])
{
    uint8_t i, j;
    for (i = 0;  i < SIZE; ++i)
        for (j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == 0)
                return true;
        }
    return false;
}

bool hasPair(uint8_t (*matrix)[SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; ++i)
        for (j = 0; j < SIZE - 1; ++j)
            if (matrix[i][j] == matrix[i][j+1])
                return true;
    return false;
}

bool canMove(uint8_t (*matrix)[SIZE])
{
    bool canMove = false;
    if (hasPair(matrix))
        return true;
    rotateMatrix(matrix);
    if (hasPair(matrix))
        canMove = true;
    rotateMatrix(matrix);
    rotateMatrix(matrix);
    rotateMatrix(matrix);
    return canMove;

}

bool gameover(uint8_t (*matrix)[SIZE])
{
    bool gameover = true;
    if (hasEmpty(matrix))
        return false;
    if (canMove(matrix))
        return false;
    return gameover;
}

int test() {
    uint8_t array[SIZE];
    // these are exponents with base 2 (1=2 2=4 3=8)
    uint8_t data[] = {
            0, 0, 0, 1, 1, 0, 0, 0,
            0, 0, 1, 1, 2, 0, 0, 0,
            0, 1, 0, 1, 2, 0, 0, 0,
            1, 0, 0, 1, 2, 0, 0, 0,
            1, 0, 1, 0, 2, 0, 0, 0,
            1, 1, 1, 0, 2, 1, 0, 0,
            1, 0, 1, 1, 2, 1, 0, 0,
            1, 1, 0, 1, 2, 1, 0, 0,
            1, 1, 1, 1, 2, 2, 0, 0,
            2, 2, 1, 1, 3, 2, 0, 0,
            1, 1, 2, 2, 2, 3, 0, 0,
            3, 0, 1, 1, 3, 2, 0, 0,
            2, 0, 1, 1, 2, 2, 0, 0
    };
    uint8_t *in, *out;
    uint8_t t, tests;
    uint8_t i;
    bool success = true;

    tests = (sizeof(data) / sizeof(data[0])) / (2 * SIZE);
    for (t = 0; t < tests; t++) {
        in = data + t * 2 * SIZE;
        out = in + SIZE;
        for (i = 0; i < SIZE; i++) {
            array[i] = in[i];
        }
        slideArray(array);
        for (i = 0; i < SIZE; i++) {
            if (array[i] != out[i]) {
                success = false;
            }
        }
        if (success == false) {
            for (i = 0; i < SIZE; i++) {
                printf("%d ", in[i]);
            }
            printf("=> ");
            for (i = 0; i < SIZE; i++) {
                printf("%d ", array[i]);
            }
            printf("expected ");
            for (i = 0; i < SIZE; i++) {
                printf("%d ", in[i]);
            }
            printf("=> ");
            for (i = 0; i < SIZE; i++) {
                printf("%d ", out[i]);
            }
            printf("\n");
            break;
        }
    }
    if (success) {
        printf("All %u tests executed successfully\n", tests);
    }
    return !success;
}