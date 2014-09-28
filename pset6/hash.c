/*
Helper functions for hash tables; descriptions of each in hash.h
*/

#include "hash.h"

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int hashFunction(char* key)
{
    int hash = tolower(key[0] - 'a');
    return hash % ALPHABET;
}

int constHashFunction(const char* key)
{
    if(isupper(key[0]) != 0)
    {
        int hash = key[0] - 'A';
        return hash % ALPHABET;
    }
    else
    {
        int hash = key[0] - 'a';
        return hash % ALPHABET;
    }
}

void SortedInsert(node** headRef, char* newWord)
{
    node* current;
    current = *headRef;
    node* newNode = malloc(sizeof(node));
    for(int i = 0; i <= strlen(newWord); i++) newNode->word[i] = newWord[i];
        
    while(current->next != NULL) current = current->next;
    newNode->next = NULL;
    current->next = newNode;
}

void DeleteList(node** headRef)
{
    node* cursor = *headRef;
    node* next;
    
    while(cursor != NULL)
    {
        next = cursor->next;
        free(cursor);
        cursor = next;
    }
    *headRef = NULL;
}


