#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 100/*get_int("Start size: ")*/;
    int end = 200/*get_int("End size: ")*/;
    int year = 0;
    //do
    //{
        int llamas = n;
        n = n + (n/3);
        n = n - (n/4);
        year++;
    //}
    //while (n <= end);
    printf("%i, %i, Years: %i\n", n, end, year);
    printf("%i", llamas);
}
