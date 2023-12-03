#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Start size: ");
    int end = get_int("End size: ");
    int year = 0;
    while (n < end)
    {
        n += n/3;
        n -= n/4;
        year++;
        printf("%i", year);
    }
    printf("Years: %i", year);
}
