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
    if (first 3 bytes are 0xff 0xd8 0xff AND 4th byte is 0xe* (* denotes anything)) {
        this is a photo; remember the pointer
    }





    */


}
