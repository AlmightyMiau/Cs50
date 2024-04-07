#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc > 1) {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    // Remember filenames
    char *infile = argv[optind];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    fread(infile, sizeof(RGBTRIPLE), width, inptr);

    /*
    files = 0
    for (file length)
    {
        if (first 3 bytes are 0xff 0xd8 0xff AND 4th byte is 0xe* (* denotes anything))
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
            fread(&data, sizeof(uint32_t), 16 * photolength, inptr);
            // write the photo from data
            fwrite(&data, sizeof(uint32_t), 16 * photolength, point);
            // Close the photo file
            // repeat this process for other photos
        }
    }





    */


}
