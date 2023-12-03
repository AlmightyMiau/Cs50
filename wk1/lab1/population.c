#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Start size: ");
    int end = get_int("End size: ");
    int year = 0;
    int llamas = n;
    while (llamas <= end)
    {
        llamas += (n/3);
        llamas -= (n/4);
        n = llamas;
        year++;
    }
    printf("Years: %i\n", year);
}
