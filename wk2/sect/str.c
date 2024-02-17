#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = "Emma";
    int l = strlen(name);
    for (int i = 0; i < l; i++)
    {
        printf("%i ", name[i]);
    }
    printf("\n");
}
