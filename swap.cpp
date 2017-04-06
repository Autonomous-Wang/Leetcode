#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;



void swap(int* a, int* b)
{
	int c; // we should swap what the pointer point to 
	c = *a;
	*a = *b;
	*b = c;
}

void charSwap(char** a, char** b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 1;
    int b = 2;
    swap(&a, &b);
    cout << a << ' ' << b << endl;

    char* x = "Hello";
    char* y = "World";
    charSwap(&x, &y);
    assert(strcmp(x, "world") == 0);
    assert(strcmp(y, "Hello") == 0);
    
}