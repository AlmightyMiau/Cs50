#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i = get_int("i: ");
    int j = get_int("j: ");

    if (i==j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
