#include <stdio.h>

int binsearch(int, int[], int);
int binsearch2(int, int[], int);

int main(int argc, char const* argv[])
{
    int v[] = {1, 3, 4, 5, 6, 8, 9};
    printf("%d \n", binsearch(8, v, 7));
    printf("%d \n", binsearch2(8, v, 7));
    return 0;
}

int binsearch2(int x, int v[], int len)
{
    int low, mid, height, count;
    low = 0;
    height = len - 1;
    count = 0;
    while(low <= height) {
        mid = (low + height) / 2;
        if (v[mid] < x) {
            low = mid + 1;
        } else if (v[mid] > x) {
            height = mid;
        } else {
            printf("binsearch2 search count: %d\n", count);
            return mid;
        }
        ++count;
    }
    printf("binsearch2 search count: %d\n", count);
    return -1;
}

int binsearch(int x, int v[], int len)
{
    int low, mid, height, count;
    low = 0;
    height = len - 1;
    count = 0;
    while (low < height) {
        mid = (low + height) / 2;
        if (v[mid] < x)
            low = mid + 1;
        else
            height = mid;
        ++count;
    }
    printf("search count: %d\n", count);
    return x == v[low] ? low : -1;
}
