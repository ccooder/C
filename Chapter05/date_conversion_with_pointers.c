#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

/*Amazing: This code is a legitimate use of char for storing small non-character
integers.
*/
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(int argc, char const* argv[])
{
    int doy, yearday, year, m, n;
    doy = day_of_year(2018, 7, 2);
    printf("%d\n", doy);

    yearday = 184;
    year = 2018;
    month_day(year, yearday, &m, &n);
    printf("month=%d, day=%d \n", m, n);

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap, doy;
    leap = year % 4 != 0 && year % 100 == 0 || year % 400 == 0;
    for (i = 1, doy=0; i < month; ++i) {
        doy += daytab[leap][i];
    }
    return doy + day;
}

void month_day(int year, int doy, int *pmonth, int *pday)
{
    int leap, i;
    leap = year % 4 != 0 && year % 100 == 0 || year % 400 == 0;
    for (i=1; doy > daytab[leap][i]; ++i)
        doy -= daytab[leap][i];
    *pmonth = i;
    *pday = doy;
}
