#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    // Open input file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    // initialize variables for use in restoring jpegs
    uint8_t buffer[512];
    int files = -1;
    char *name[8];

    //
    while(fread(buffer, 1, 512, card) == 512)
    {
        // create new files from data
        if (
            buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            buffer[3] >= 0xe0 &&
            buffer[3] <= 0xef
        )
        {
            // this is a jpeg, make a new file from it
            files++;
            sprintf(name, "%i%i%i.jpg", files / 100, (files / 10) % 10, files % 10);
            fopen(name, "w");
            fwrite(buffer, 1, 512, name);
            fclose(name);
        }
        else if(files >= 0)
        {
            fopen(name, "a");
            fwrite(buffer, 1, 512, name);
            fclose(name);
        }
    }
    fclose(card);

    /*
    files = 0
    for (file length)
    {
        if (first 3 bytes are 0xff 0xd8 0xff AND 4th byte is 0xe* (* denotes anything))
        fread(ptr, )
        {
            this is a photo; remember the pointer (call it point)
            int photolength = 0;
            // look through the blocks ahead of this one for a new photo
            for (file length left)
            {
                photolength++;
                if (first 3 bytes are 0xff 0xd8 0xff AND 4th byte is 0xe* (* denotes anything))
                {
                    // this is the photo length
                    break
                }
            }
            filename = files.jpg
            files++
            Open output file with name (filename)

            // make buffer space to store the data
            uint32_t data[photolength][16];
            // read the photo to data in blocks of 32 bits
            fread(&data, sizeof(uint8_t), 16 * photolength, card);
            // write the photo from data
            fwrite(&data, sizeof(uint8_t), 16 * photolength, point);
            // Close the photo file
            // repeat this process for other photos
        }
    }





    */

}
