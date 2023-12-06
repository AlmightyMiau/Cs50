#include <cs50.h>
#include <stdio.h>

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
    int i = 1;
    do
    {
        array[i] = array[i - 1] * 2;
        i++;
    }
    while (i < n);
    for (int j = 0; j < n; j++)
    {
        printf("%i\n", array[j]);
    }
}
