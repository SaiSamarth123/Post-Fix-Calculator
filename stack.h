// stack.h
// Contains the function prototypes of stack.c so it can be accessed by other files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define TRUE 1
#define FALSE 0

typedef struct stack {
    treeNode* node;
    struct stack* next;
}node; 

void pop(node** hd);
node* init ();
int isEmpty(node* hd);
void push(treeNode* n, node** hd);
void clear(treeNode* n);
void printCommands();