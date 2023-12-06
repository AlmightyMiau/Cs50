#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int l = strlen(word);
    for (int i = 0; i < l; i++)
    {
        if (((word[i] > 96 && word[i] < 123) && (word[i - 1] > 96 && word[i - 1] < 123) && (word[i] > word[i - 1])))
        {
            int a = word[i];
            word[i] = word[i - 1];
            word[i - 1] = a;
        }
    }
    printf("%s\n", word);
}
