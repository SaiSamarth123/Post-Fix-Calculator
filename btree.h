// btree.h
// Contains the function prototypes of btree.c so it can be accessed by other files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>


#define TRUE 1
#define FALSE 0

typedef struct treeNode {
    struct treeNode* left;
    struct treeNode* right;
    char* token;
} treeNode;

void postOrder(treeNode* root);
void preOrder(treeNode* root);
void inOrder(treeNode* root);
int checkDigit(char token[]);
int isOperator(char token[]);
treeNode* parseExpression(char token[]);
int evalExpression(treeNode* root, int val);