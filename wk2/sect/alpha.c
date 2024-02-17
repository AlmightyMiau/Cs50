#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int l = strlen(word);
    for (int i = 0; i < l - 1; i++)
    {
        // If NOT alphabetical
        if (word[i] > word[i + 1])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}
