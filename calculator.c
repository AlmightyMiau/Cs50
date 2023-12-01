#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long x = get_int("x: ");
    long y = get_int("y: ");

    float z = (float) x / (float) y;
    printf("%.20f\n", z);
}
