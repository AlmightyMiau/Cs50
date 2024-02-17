#include <stdio.h>
#include <cs50.h>

//argc is argument count, ie how many arguments were given
//argv is an array of the arguments given
//argv[0] is the command that calls the script, ie ./greet
int main(int argc, string argv[])
{
    printf("hello, %s\n", argv[1]);
}
