#include <stdio.h>

void shellsort(int[], int);
void bubblesort(int[], int);
void selectsort(int[], int);

int main(int argc, char const* argv[])
{
    int i, n;
    int v[] = {9, 3, 7, 2, 4, 6, 5, 1, 8};
    n = 9;
    //int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("排序前:");

    for (i=0; i<n; ++i) {
        printf("%d\t", v[i]);
    }
    //shellsort(v, n);
    bubblesort(v, n);
    printf("\n排序后:");
    for (i=0; i<n; ++i) {
        printf("%d\t", v[i]);
    }
    printf("\n");
    return 0;
}

void shellsort(int v[], int n)
{
    int gap, i, j, temp, l_count, c_count;
    l_count = 0;
    c_count = 0;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; ++i)
            for (j = i-gap; j >= 0; j -= gap) {
                ++l_count;
                if (v[j] > v[j + gap]) {
                    ++c_count;
                    temp = v[j];
                    v[j] = v[j+gap];
                    v[j+gap] = temp;
                }
            }
    printf("\nshellsort循环次数:%d,交换次数:%d.", l_count, c_count);
}

//优化后的冒泡排序算法，可以减少交换次数
void bubblesort(int v[], int n)
{
    int i, j, k;
    int c_count, l_count;

    c_count = 0;
    l_count = 0;
    for (i = 0; i < n-1; ++i) {
        for (j = i+1, k=i; j < n; ++j) {
            ++l_count;
            if (v[k] > v[j]) {
                k = j;
            }
        }
        if(k != i) {
            ++c_count;
            int temp = v[i];
            v[i] = v[k];
            v[k] = temp;
        }
    }
    printf("\nbubblesort循环次数:%d,交换次数:%d.", l_count, c_count);
}
