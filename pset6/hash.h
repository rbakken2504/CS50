#ifndef HASH_H
#define HASH_H

#define ALPHABET 26
#define LENGTH 45

//Node struct
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
    
}node;

//hash function to determine array index
int hashFunction(char* key);

//C doesn't support overloading, so hash funtion to deal with const param
int constHashFunction(const char* key);

//Linked list insert to add nodes to the tail of each list
void SortedInsert(node** headRef, char* newWord);

//Delete the hash table
void DeleteList(node** headRef);

#endif // HASH_H
