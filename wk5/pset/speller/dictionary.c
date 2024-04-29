// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // initialize the table
    for (int i = 0; i < N; i++) {
        // malloc size of next
        table[i] = NULL;
    }

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
    while(fscanf(source, "%s", word) == 1)
    {
        // update size int
        siz++;
        // create new node
        // use malloc
        node *ptr = malloc(sizeof(node));
        // check if return is NULL
        if (ptr == NULL)
        {
            fclose(source);
            return false;
        }
        // copy word from fscanf into node using strcpy
        strcpy(ptr->word, word);
        // set the new ptr
        ptr->next = NULL;
        // hash the word to find the bucket it goes in
        int val = hash(ptr->word);
        // put new node at begining of bucket
        if (table[val] == NULL)
        {
            // if empty put it there
            table[val] = ptr;
        }
        else
        {
            // if not empty move the current first one down,
            // then put the new one there
            ptr->next = table[val];
            table[val] = ptr;
        }

    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // for every bucket
    for (int i = 0; i < N; i++)
    {
        // while there's more in the bucket
        node *current = table[i];
        while (current != NULL)
        {
            // record position of this node
            node *this = current;
            // record position of next node
            current = current->next;
            // free this node
            free(this);
        }
    }
    return true;
}
