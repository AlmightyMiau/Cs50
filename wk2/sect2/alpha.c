#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int l = strlen(word);
    int k = 0;
    for (int i = 0; i < l; i++)
    {
        if (((word[i] > 96 && word[i] < 123) && (word[i - 1] > 96 && word[i - 1] < 123) && (word[i] > word[i - 1])))
        {

        }
    }
    if ()
    {
        printf("%s\n", word);
    }
}
