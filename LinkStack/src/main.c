#include "include\LinkStack.h"

int main()
{
    LinkStack S;
    Status s;

    int k;
    int e;

    s = InitStack(&S);
    if( s == ERROR )
        exit(EXIT_FAILURE);
    
    for( k = 1; k <= 10; k++ )
    {
        Push( &S, k );
    }
    
    printf("The Link Stack is empty or not ? %d (1. Empty  0. Not Empty) .\n", StackEmpty(S));
    PrintStack(S);

    GetTop( S, &e );
    printf("The top element in the stack is %d.\n", e);

    Pop( &S, &e );
    printf("Pop the element %d from the Stack.\n", e );

    printf("The length of the Link Stack now is %d.\n", StackLength(S));

    ClearStack(&S);
    printf("After clearing the Stack, the Stack is Empty? %d (1. Empty  0. Not Empty) .\n", StackEmpty(S));
    printf("After clearing the Stack, the lenght of the Stack is %d.\n", StackLength(S) );

    system("PAUSE");
    return 0;
}