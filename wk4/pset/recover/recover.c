#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Remember filenames
    char *infile = argv[optind];

    // Open input file
    FILE *inptr = fopen(infile, "r");

    
    fread("card.raw", sizeof(RGBTRIPLE), width, inptr);
}
