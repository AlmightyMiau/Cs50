#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

/*  
    if (!strcmp(s,t))
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
*/

/*
   printf("%s\n", s);
   printf("%s\n", t);
*/
    printf("%p\n", s);
    printf("%p\n", t);
}
