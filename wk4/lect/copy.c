#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1); // allocates a piece of memory for the new string with the same length as s
    if (t == NULL)
    {
        return 1;
    }

    strcpy(t,s); // copies a string s to a new string t

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%p\n", s);
    printf("%p\n", t);

    free(t); // frees the memory allocated by malloc
    return 0;
}
