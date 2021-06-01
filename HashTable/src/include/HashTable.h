#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 12
#define NULLKEY -32768

typedef enum Status{ UNSUCCESS, SUCCESS }Status;

typedef struct HashTable
{
    int *elem;
    int count;
}HashTable;

Status InitHashTable( HashTable *H );
int Hash( int key );
void InsertHash( HashTable *H, int key );
Status SearchHash( HashTable H, int key, int *addr );

#endif