#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 40
#define bool int

typedef enum Status{ OK, ERROR }Status;

typedef char String[MAXSIZE + 1];

Status StrAssign( String S, char *chars);
Status StrCopy( String T, String S );
Status ClearString( String S );
bool StringEmpty( String S );
int StrLength( String S );
int StrCompare( String S, String T );
Status StringConcat( String T, String S1, String S2 );
Status SubString( String T, String S, int pos, int len );
int Index( String S, String T, int pos );
void get_Next( String T, int *next );
int Index_KMP( String S, String T, int pos );
Status Replace( String S, String T, String V );
Status StrInsert( String S, int pos, String T );
Status StrDelete( String S, int pos, int len );

void StrPrint( String T );

#endif