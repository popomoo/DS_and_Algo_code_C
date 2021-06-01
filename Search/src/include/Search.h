#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int Sequential_Search( int *a, int n, int key );
int Sequential_Search2( int *a, int n, int key );
int Binary_Search( int *a, int n, int key );
int Interpolation_Search( int *a, int n, int key );
void Fibonacci();
int Fibonacci_Search( int *a, int n, int key );

#endif