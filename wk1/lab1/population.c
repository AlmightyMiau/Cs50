#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
    n = get_int("Start size: ");
    }
    while (n < 9);
    int end;
    do
    {
    end = get_int("End size: ");
    }
    while (end <= n);
    int year = 0;
    while (n < end)
    {
        n += (n/12);
        year++;
    }
    printf("Years: %i\n", year);
}
