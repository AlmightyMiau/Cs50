#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string first = get_string("What's your first name? ");
    char middle = get_char("What's your middle INITIAL? ");
    string last = get_string("What's your last name? ");
    printf("Hello, %s %c %s\n", first, middle, last);
}
