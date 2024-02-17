#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    string text = get_string("Text: ");
    float s = 0;
    float w = 1;
    float l = 0;
    int i = 0;
    char c;
    do
    {
        c = text[i];
        int j = c;
        i++;
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
    // printf("s: %f w: %f l: %f\n", s, w, l);
    float L = (float) (l / w) * 100;
    float S = (double) (s / w) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int ans = round(index);
        if (ans >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", ans);
        }
    }
}
