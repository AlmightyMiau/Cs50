#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Length: ");
    }
    while (n < 1);
    int array[n];
    array[0] = 1;
    printf("1\n");
    int i = 1;
    do
    {
        array[i] = array[i-1] * 2;
        printf("%i\n", array[i]);
        i++;
    }
    while (i < n);
}
