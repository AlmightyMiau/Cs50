#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long x = get_int("x: ");
    long y = get_int("y: ");

    double z = (double) x / (double) y;
    printf("%.20f\n", z);
}
