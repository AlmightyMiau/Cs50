#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Start size: ");
    int end = get_int("End size: ");
    int year = 0;
    //while (n <= end)
    //{
        n = n + (n/3);
        n = n - (n/4);
        year = year + 1;
    //}
    printf("Years: %i", year);
}
