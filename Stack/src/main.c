#include "include\Stack.h"

int main()
{
    Stack S;

    Status s;
    int i;
    int e;

    s = InitStack(&S);
    if( s == OK )
    {
        for( i = 1; i <= 10; i++ )
            Push( &S, i );
    }

    printf(" The elements in the Stack :\n");
    PrintStack( S );

    Pop( &S, &e );
    printf("Pop the element %d.\n", e);

    printf("Whether the Stack is empty? %d (1. Empty 0. Not Empty)\n", StackEmpty(S));

    GetTop(S, &e);
    printf("The top element in the Stack e = %d.\n", e);
    printf("The length of the Stack is %d.\n", StackLength(S));

    ClearStack(&S);
    printf("After clearing the Stack, the Stack is empty or not : %d( 1. Empty 0. Not Empty)\n", StackEmpty(S));

    system("PAUSE");
    return 0;

}