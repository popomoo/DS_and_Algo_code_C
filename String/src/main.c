#include "include\String.h"

int main()
{
    Status k;
    String t, s1, s2;
    char s;
    int i, j;

    k = StrAssign( s1, "abcd" );
    if( k == ERROR )
    {
        printf("The length of the string has passed the MAXSIZE %d.\n", MAXSIZE);
        exit(0);
    }
    printf("The length of the string is : %d, the string is empty or not? %d( 1. Empty 0. Not empty).\n", StrLength(s1), StringEmpty(s1) );
    
    StrCopy( s2, s1 );
    printf("The string copied from the string s1 is : ");
    StrPrint( s2 );
    
    k = StrAssign(s2, "efghijk");
    if( k == ERROR )
    {
        printf("The length of the string has passed MAXSIZE %d.\n", MAXSIZE );
        exit(0);
    }

    i = StrCompare( s1, s2 );
    if( i < 0 )
        s = '<';
    else if( i == 0 )
        s = '=';
    else
        s = '>';
    printf("String S1 %c String s2\n", s );

    k = StringConcat(t, s1, s2);
    if( k == ERROR )
    {
        printf("Failed to cancat the strings.\n");
        exit(0);
    }
    printf("Concat the string s1 and the string s2, the result is : ");
    StrPrint(t);
    if( k == ERROR )
        printf( "The string is cut off.\n");
    
    ClearString(s1);
    printf("After clearing the string s1, the string s1 is : ");
    StrPrint(s1);
    printf("The length of the string s1 is %d, is the string empty? %d(1.Empty 0.Not Empty)\n", StrLength(s1), StringEmpty(s1) );

    i = 2;
    j = 3;
    printf("Find the substring of the string t, the start position of the substring is %d, the length of the substring is %d.\n", i, j );
    
    k = SubString(s2, t, i, j);
    if( k == OK )
    {
        printf("The substring s2 is : ");
        StrPrint(s2);
    }

    i = 4;
    j = 2;
    printf("From the %dth character, delete %d characters.\n", i, j);
    StrDelete(t, i, j);
    printf("The deleted string t is : ");
    StrPrint(t);

    i = StrLength(s2)/2;
    StrInsert(s2, i, t);
    printf("From the %dth character of the string s2, insert the characters of the string t to the string s2, the string s2 then is :", i);
    StrPrint(s2);

    i = Index_KMP(s2, t, 1);
    printf("From the %dth character of the string s2, the characters match the string t for the first time.\n", i);

    SubString(t, s2, 1, 1);
    printf("The substring string t of the string s2 is : ");
    StrPrint(t);

    StringConcat(s1, t, t);
    printf("After concacting string t and string t, the new string is : ");
    StrPrint(s1);
    
    Replace(s2, t, s1);
    printf("Replacing the string t in the string s2 by the string s1 : ");
    StrPrint(s2);

    system("PAUSE");
    return 0;
}