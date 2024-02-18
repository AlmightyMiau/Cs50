#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    string name;
    int votes;
} candidate;

int main(void) {
    candidate president = get_candidate("Enter a candidate: ");
    president.name = "Alyssa";
    president.votes = 10;
}

candidate get_candidate(string prompt) {

}

/*
    struct makes a new
*/
