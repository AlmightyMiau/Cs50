#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string text = get_string("Text: ");
    int s = 0;
    int w = 1;
    int l = 0;
    int i = 0;
    char c;
    do
    {
        c = text[i];
        int j = c;
        i++;
        //printf("%i ", j);
        if (c == '.' || c == '!' || c == '?')
        {
            s++;
        }
        else if (c == ' ')
        {
            w++;
        }
        else if ((64 < j && j < 91) || (96 < j && j < 123))
        {
            l++;
        }
    }
    while (c != '\0');
    printf("s: %i w: %i l: %i\n", s, w, l);
    float L = (float)(l / w) * 100;
    float S = (float)(s / w) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    printf("L: %f, S: %f, Grade: %f\n", L, S, index);
}
/*

*DONE*  Your program must prompt the user for a string of text using get_string.

*DONE*  Your program should count the number of letters, words, and sentences
            in the text. You may assume that a letter is any lowercase
            character from a to z or any uppercase character from A to Z,
            any sequence of characters separated by spaces should count as
            a word, and that any occurrence of a period, exclamation point,
            or question mark indicates the end of a sentence.

Your program should print as output "Grade X" where X is the grade
    level computed by the Coleman-Liau formula, rounded to the nearest
    integer.

If the resulting index number is 16 or higher (equivalent to or
    greater than a senior undergraduate reading level), your program
    should output "Grade 16+" instead of giving the exact index
    number. If the index number is less than 1, your program should
    output "Before Grade 1".
*/
