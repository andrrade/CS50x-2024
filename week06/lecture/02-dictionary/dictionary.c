// Implements a dictionary's functionality

#include <ctype.h>   // Library for character manipulation
#include <stdbool.h> // Library for using boolean values
#include <stdio.h>   // Library for input and output operations
#include <stdlib.h>  // Library for memory allocation functions
#include <string.h>  // Library for string manipulation
#include <strings.h> // Library for string comparison functions

#include "dictionary.h" // Includes the dictionary header

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH]; // The word stored in the node
    struct node *next; // Pointer to the next node in the linked list
} node;

// Number of buckets in the hash table
const unsigned int N = 26; // One bucket for each letter of the alphabet

// Hash table
node *table[N];     // Array of pointers to nodes
int totalWords = 0; // Total count of words loaded

// Returns true if the word is in the dictionary, otherwise false
bool check(const char *word)
{
    node *cursor = table[hash(word)]; // Get the node corresponding to the word in the hash table

    // Compare words case insensitive
    if (strcasecmp(cursor->word, word) == 0)
    {
        return true; // Word found
    }

    // Continue traversing the linked list until the word is found or the end is reached
    while (cursor->next != NULL)
    {
        cursor = cursor->next; // Move to the next node
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true; // Word found
        }
    }

    return false; // Word not found
}

// Hashes the word to a number
// Uses one bucket for each letter: a = 0, b = 1, ... z = 25
unsigned int hash(const char *word)
{
    int n = (int) tolower(word[0]) -
            97; // Convert the first letter to lowercase and calculate the index
    return n;   // Return the bucket index
}

// Loads the dictionary into memory, returning true if successful, otherwise false
bool load(const char *dictionary)
{
    // Opens the dictionary file and initializes temporary space to hold the words
    FILE *file = fopen(dictionary, "r"); // Opens the file for reading
    char *dictWord = malloc(LENGTH);     // Allocates space for a word from the dictionary
    if (dictWord == NULL)                // Checks if the allocation was successful
    {
        return false; // Memory allocation failed
    }

    // Reads the file until the end
    while (fscanf(file, "%s", dictWord) != EOF) // Reads each word from the file
    {
        // Allocates memory for a node where the word will be inserted
        node *n = malloc(sizeof(node));
        if (n == NULL) // Checks if the allocation was successful
        {
            return false; // Memory allocation failed
        }

        // Copies the word into the allocated memory and updates the word count
        strcpy(n->word, dictWord);
        totalWords++;

        // Sets the next pointer to point to the beginning of the list
        n->next = table[hash(dictWord)];

        // Updates the table to point to n, which becomes the new head of the list
        table[hash(dictWord)] = n;
    }

    fclose(file);   // Closes the file
    free(dictWord); // Frees the allocated memory for dictWord
    return true;    // Returns true indicating success
}

// Returns the number of words in the dictionary if loaded, otherwise returns 0 if not yet loaded
unsigned int size(void)
{
    return totalWords; // Returns the total number of words
}

// Unloads the dictionary from memory, returning true if successful, otherwise false
bool unload(void)
{
    // Creates two pointers to traverse the linked list and free its elements without losing their
    // addresses
    node *tmp;
    node *cursor;

    // Repeats for each index in the table
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL) // If the bucket is empty, skip to the next
        {
            continue;
        }

        cursor = table[i]; // Initializes the cursor at the current bucket
        tmp = cursor;      // Initializes tmp to store the current node

        // Continues until the end of the list, freeing the memory allocated in load
        while (cursor->next != NULL)
        {
            cursor = cursor->next; // Moves to the next node
            free(tmp);             // Frees the memory of the previous node
            tmp = cursor;          // Updates tmp to the current node
        }
        free(cursor); // Frees the last node
    }
    return true; // Returns true indicating success
}
