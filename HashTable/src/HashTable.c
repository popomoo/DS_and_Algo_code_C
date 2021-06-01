#include "include\HashTable.h"

Status InitHashTable( HashTable *H )
{
    int i;
    H->elem = (int*)malloc( HASHSIZE*sizeof(int));
    H->count = HASHSIZE;
    for( i = 0; i < HASHSIZE; i++ )
        H->elem[i] = NULLKEY;
    return SUCCESS;
}

int Hash( int key )
{
    return key % HASHSIZE;
}

void InsertHash( HashTable *H, int key )
{
    int addr;
    addr = Hash(key);
    while( H->elem[addr] != NULLKEY && addr < HASHSIZE )
        addr = (addr + 1) % HASHSIZE;
    H->elem[addr] = key;
}

Status SearchHash( HashTable H, int key, int *addr )
{
    *addr = Hash(key);
    while( H.elem[*addr] != key )
    {    *addr = (*addr + 1) % HASHSIZE;
        if( H.elem[*addr] == NULLKEY || *addr == Hash(key) )
            return UNSUCCESS;
    }
    return SUCCESS;
}