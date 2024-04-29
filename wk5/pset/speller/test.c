#include <cs50.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Hashes word to a number
int main(void)
{
    char *word = "scatter";
    // (sum of (letter - 'A') % 26) of a word to get a value of where to store it in the hash table
    int val = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        val += toupper(word[i]) - 'A';
    }
    printf("%i\n", val %= 26);
}
