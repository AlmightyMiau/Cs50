#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    // Open input file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // initialize variables for use in restoring jpegs
    uint8_t buffer[512];
    int files = -1;
    char name[8];

    // restoring jpegs
    while (fread(buffer, 1, 512, card) == 512)
    {
        // check if this is a new picture
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 &&
            buffer[3] <= 0xef)
        {
            // this is a jpeg, make a new file from it
            files++;
            sprintf(name, "%i%i%i.jpg", files / 100, (files / 10) % 10, files % 10);
            FILE *point = fopen(name, "w");
            fwrite(buffer, 1, 512, point);
            fclose(point);
        }
        else if (files >= 0) // if it is part of a previous picture, add to it
        {
            FILE *point = fopen(name, "a");
            fwrite(buffer, 1, 512, point);
            fclose(point);
        }
    }
    fclose(card);
}
