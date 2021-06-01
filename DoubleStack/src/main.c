#include "include\DoubleStack.h"

int main()
{
    DoubleStack S;
    Status s;
    int k;
    int e;

    s = InitDoubleStack(&S);
    if( s == ERROR )
        exit( EXIT_FAILURE );
    
    for( k = 1; k <= 15; k++ )
    {
        Push( &S, k, 1 );
        Push( &S, k+10, 2 );
    }
    PrintStack( S );

    printf("Is the Stack1 Empty ? %d  (1. Empty  0. NotEmpty)\n", DoubleStackEmpty(S, 1));
    printf("Is the Stack2 Empty ? %d  (1. Empty  0. NotEmpty)\n", DoubleStackEmpty(S, 2));
    printf("The length of the Stack 1 is %d.\n", DoubleStackLength(S, 1));
    printf("The length of the Stack 2 is %d.\n", DoubleStackLength(S, 2));

    Pop(&S, &e, 1);
    printf("Pop an element %d from the stack 1.\n", e);
    PrintStack( S );

    Pop(&S, &e, 2);
    printf("Pop an element %d from the stack 2.\n", e);
    PrintStack( S );

    ClearDoubleStack(&S);
    printf("After clearing the Stack :\n");
    printf("Is the Stack1 Empty ? %d  (1. Empty  0. NotEmpty)\n", DoubleStackEmpty(S, 1));
    printf("Is the Stack2 Empty ? %d  (1. Empty  0. NotEmpty)\n", DoubleStackEmpty(S, 2));
    printf("The length of the Stack 1 is %d.\n", DoubleStackLength(S, 1));
    printf("The length of the Stack 2 is %d.\n", DoubleStackLength(S, 2));

    system("PAUSE");
    return 0;
}

