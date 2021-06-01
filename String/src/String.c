#include "include\String.h"

Status StrAssign( String S, char *chars )
{
    
    int i = 1;
    if( chars == NULL || strlen(chars) > MAXSIZE )
        return ERROR;
    else
    {
        for( i = 1; i <= strlen(chars); i++ )
        {
            S[i] = *(chars + i - 1);
        }
        S[0] = i - 1;
        return OK;
    }
}

Status StrCopy( String T, String S )
{
    int i = 0;
    if( StrLength(T) < StrLength(S) )
        return ERROR;
    
    if( StrLength(S) == 0 )
        return ERROR;

    while( i <= StrLength(S) )
    {
        T[i] = S[i];
        i++;
    }
    return OK;
}

Status ClearString( String S )
{
    int i = S[0];
    while( i > 0 )
    {
        S[i] = '\0';
        i--;
    }
    S[0] = 0;
    return OK;
}

bool StringEmpty( String S ){
    return ( S[0] == 0 );
}

int StrLength( String S )
{
    return S[0];
}

int StrCompare( String S, String T )
{
    int i = 1;
    while( i <= StrLength(S) && i <= StrLength(T) )
    {
        if( S[i] != T[i] )
            return S[i] - T[i];
    }

    return (StrLength(S) - StrLength(T));
}

Status StringConcat( String T, String S1, String S2 )
{
    int i;
    int L_S1, L_S2;
    L_S1 = StrLength(S1);
    L_S2 = StrLength(S2);

    for( i = 1; i <= L_S1; i++ )
        T[i] = S1[i];
            
    if( L_S1 + L_S2 <= MAXSIZE )
    {
        for( i = 1; i <= L_S2; i++ )
            T[i + L_S1] = S2[i];
        
        T[0] = L_S1 + L_S2;
    }
    else
    {
        for( i = 1; i <= MAXSIZE-L_S1; i++ )
            T[i + L_S1] = S2[i];

        T[0] = MAXSIZE;
    }
    return OK;
    
}

Status SubString( String T, String S, int pos, int len )
{
    int i = pos;
    if( StrLength(T) < len )
        return ERROR;
    if( pos <= 0 || pos > StrLength(S) )
        return ERROR;
    if( len < 0 || len > (StrLength(S) - pos + 1) )
        return ERROR;

    for( i = 1; i <= len; i++ )
        T[i] = S[i+pos-1];// i + pos - 1

    T[0] = len;

    return OK;
}

int Index( String S, String T, int pos )
{
    int i = pos;
    int j = 1;
    if( StrLength(T) == 0 )
        return ERROR;

    if( pos <= 0 || pos > StrLength(S) )
        return ERROR;

    while( i <= StrLength(T) && j <= StrLength(S) )
    {
        if( S[i] == T[j] )
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }

    if( j > StrLength(T) )
        return (i - StrLength(T));
    else
        return 0;
}

void get_Next( String S, int *next )
{
    int k = 0;
    int i = 1;
    next[i] = 0;
    while( i <= StrLength(S) )
    {
        if( k == 0 || S[i] == S[k] )
        {
            i++;
            k++;
            if( S[i] != S[k] )
                next[i] = k;
            else
                next[i] = next[k];
        }
        else
            k = next[k];
    }
}

int Index_KMP( String S, String T, int pos )
{
    int i = pos;
    int j = 1;
    int next[255];
    get_Next( S, next );
    while( i <= StrLength(S) || j <= StrLength(T) )
    {
        if( j == 0 || S[i] == T[j] )
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }

    if( j > StrLength(T) )
        return i - StrLength(T);
    else
        return 0;
}

Status Replace( String S, String T, String V )
{
    int i = 1;
    int pos = 1;
    if( StrLength(S) == 0 &&
        StrLength(T) == 0 &&
        StrLength(V) == 0 )
        return ERROR;

    while( i != 0 )
    {
        i = Index( S, T, pos );
        if( i != 0 )
        {
            StrDelete( S, i, StrLength(T) );
            StrInsert( S, i, V );
            pos += StrLength(V);
        }
    }
    return OK;
}

Status StrInsert( String S, int pos, String T )
{
    int i;
    int L_S = StrLength(S);
    int L_T = StrLength(T);

    if( pos <= 0 || pos > StrLength(S) + 1 )
        return ERROR;
    
    if( L_S + L_T <= MAXSIZE )
    {
        for( i = L_S; i >= pos; i-- )
            S[i + L_T] = S[i];
        for( i = pos; i < pos + L_T; i++ )
            S[i] = T[i - pos + 1];
        S[0] = L_S + L_T;
        return ERROR;
    }
    else
    {
        for( i = MAXSIZE; i >= pos+L_T; i-- )
            S[i] = S[i-L_T];
        for( i = pos; i < pos + L_T; i++ )
            S[i] = T[ i - pos + 1];
        S[0] = MAXSIZE;
        return OK;
    }
}

Status StrDelete( String S, int pos, int len )
{
    int i;
    if( pos <= 0 || pos > StrLength(S) - len + 1 )
        return ERROR;

    for( i = pos; i <= StrLength(S) - len; i++ )
        S[i] = S[i+len];

    S[0] -= len;
    return OK;
}

void StrPrint( String T )
{
    int i;
    for( i = 1; i <= StrLength(T); i++ )
        printf("%c", T[i]);
    printf("\n");
}