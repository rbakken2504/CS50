/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"
#include "hash.h"

//Global variables that more than one function needs access to.
int wordCount = 0;
bool isLoaded = false;
node* hashTable[ALPHABET];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int index = constHashFunction(word);
    
    //grab the head node from the correct index
    node* current = hashTable[index];
    
    //traverse list checking each node's .word for a match and ignoring case.
    while(current != NULL)
    {
        if(strncasecmp(word, current->word, LENGTH + 1) == 0) return true;
        else current = current->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* file = fopen(dictionary, "r");
    char line[LENGTH + 1];
    
    //boolean array to track with indices have a head node already
    bool occupied[ALPHABET];
    //initialize the array
    for(int i = 0; i < ALPHABET; i++) occupied[i] = false;
    char* newWord;
    
    while(fgets(line, sizeof(line), file))
    {
        //removes the '\n' char that fgets grabs and replaces with null terminator
        size_t ln = strlen(line) - 1;
        if(line[ln] == '\n') line[ln] = '\0';
        newWord = line;
        int index = hashFunction(newWord);
        //if no head node, insert node as head node into proper index.
        if(occupied[index] == false)
        {
            node* firstNode = calloc(1,sizeof(node));
            for(int i = 0; i <= strlen(newWord); i++) firstNode->word[i] = newWord[i];
            hashTable[index] = firstNode;
            occupied[index] = true;
        }
        //else insert at tail end of the proper index
        else
        { 
            SortedInsert(&hashTable[index], newWord);
            //wordCount++;
        }
        //check for empty line 
        if(line[0] != '\n' && line[0] != '\0') wordCount++;
    }
    //check for errors and that the file was closed successfully
    if(ferror(file) == 0 && fclose(file) == 0)
    {   
        isLoaded = true;
        return true;    
    }
    else return false;
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if(isLoaded) return wordCount;
    else return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0; i < ALPHABET; i++) DeleteList(&hashTable[i]);
    return true;
}
