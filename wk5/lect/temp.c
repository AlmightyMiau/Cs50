#include <cs50.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *n = malloc(sizeof(node));
    n->number = 1;
    n->next = NULL;
    list = n;

    node *n = malloc(sizeof(node));
    n->number = 2;
    n->next = list;
    list = n;

    // This creates a linked list where 2 points to 1
}
