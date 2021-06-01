#include "include\ThreadBiTree.h"

int main()
{
    ThrBiTree H, T;
    
    printf("Please input the Binary tree.( Ex:ABDH##I##EJ###CF##G )\n");
    StrAssign( str, "ABDH##I##EJ###CF##G##" );
    CreateBiThrTree( &T );
    InOrderThreading( &H, T );
    printf("InOrder Threading output the thread binary tree:\n");
    InOrderTraverse_Thr(H);
    printf("\n");

    DestroyBiThrTree(&H);

    system("PAUSE");
    return 0;
}