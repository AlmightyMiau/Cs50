// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // (sum of (letter - 'A') % 26) of a word to get a value of where to store it in the hash table
    int val = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        val += toupper(word[i]) - 'A';
    }
    return val %= 26;
}


// TODO
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    //read each word in dictionary
    char word[LENGTH + 1];
    // use fscanf(file, "%s", word) to grab words
    // check for ended file
    while(fscanf(source, "%s", word) != "E0F")
    {
        // create new node
        // use malloc
        node *ptr = malloc(sizefo(node));
        // check if return is NULL
        if (ptr == NULL)
        {
            fclose(source);
            return false;
        }
        // copy word from fscanf into node using strcpy
        strcpy(ptr->word, word);
        hash(word);
        ptr->next = 
    }

    /*
    use hash function
        function takes string and returns index
    insert node into hash table
        HOW
    */

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    char c;
    int n = 0;
    while (fread(&c, 1, 1, file))
    {
        if (c == "\n")
        {
            n++;
        }
    }
    return n;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
