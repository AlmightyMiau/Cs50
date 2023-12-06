#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int l = strlen(word);
    int k = 1;
    for (int i = 1; i < l; i++)
    {
        if (word[i] < word[i - 1])
        {
            k++;
        }
    }
    if (k == l)
    {
        printf("Yes\n");
    }
    if (k != l)
    {
        printf("No\n");
    }
}
