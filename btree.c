// btree.c
// Contains functions that manipulate the tree and print its contents in different
// orders. 
#include "btree.h"
#include "stack.h"

/********************************************************
 * Function:       isOperator
 * Parameters:    C-style char array 
 * Return value:   int
 *******************************************************/
int isOperator(char token[]) {
  // check if operator is in first element of char array
	if ( (token[0] == '-') || (token[0] == '+') || (token[0] == '*') || (token[0] == '/') ) {
    // 0 indicates operator is found
		return 1;
	}
  // 1 indicates operator is not found
	return 0;
}
/********************************************************
 * Function:       postOrder
 * Parameters:    C-style pass-by-value head pointer 
 * Return value:   None
 *******************************************************/
void postOrder(treeNode* root) {
    if (root == NULL) {
        return;
    }
    // visit left subtree
    postOrder(root->left);
    // visit right subtree
    postOrder(root->right);
    // print root token
    printf(" %s ", root->token);
}
/********************************************************
 * Function:       preOrder
 * Parameters:    C-style pass-by-value root pointer
 * Return value:   None
 *******************************************************/
void preOrder(treeNode* root) {
    if (root == NULL) {
        return;
    }
    // print root token
    printf(" %s ", root->token);
    // visit left subtree
    preOrder(root->left);
    // visit right subtree
    preOrder(root->right);
}
/********************************************************
 * Function:       inOrder
 * Parameters:    C-style pass-by-value root pointer 
 * Return value:   None
 *******************************************************/
void inOrder(treeNode* root) {
    if (!root) {
        return;
    }
    // if root is operator print (
    if (isOperator(root->token)) {
        printf("(");
    }
    // visit left subtree
    inOrder(root->left);
    // print root token
    printf(" %s ", root->token);
    // visit right subtree
    inOrder(root->right);
    // if last token is operator print )
    if (isOperator(root->token)) {
        printf(")");
    }
}

/********************************************************
 * Function:       checkDigit
 * Parameters:     C-style char array
 * Return value:   int
 *******************************************************/
int checkDigit(char token[]) {
  // for loop to go through the array
    for(int i = 0; i < strlen(token); i++) {
        if (!isdigit(token[i])) { // check if it is not a digit
            return 0;
        }
    }
    return 1; // return true if it is digit
}
/********************************************************
 * Function:       parseExpression
 * Parameters:     C-style char array
 * Return value:   None
 *******************************************************/
treeNode * parseExpression(char token[]) {
  node * hd = init(); // initialize the head
  treeNode * root = NULL; // treeNode that we return
  char * ptr = strtok(token, " ");
  while (ptr != NULL) {
    int i = checkDigit(ptr);
    if (i) {
      // creating new treeNode for operands
      treeNode * tree = (treeNode * ) malloc(sizeof(treeNode));
      tree -> left = NULL;
      tree -> right = NULL;
      tree -> token = ptr;
      push(tree, &hd);
    } else if ((ptr[0] == '-') || (ptr[0] == '+') || (ptr[0] == '*') || (ptr[0] == '/')) {
      // creating new treeNode for operators
      treeNode * treeOp = (treeNode * ) malloc(sizeof(treeNode));
      treeOp -> token = ptr;
      treeOp -> left = NULL;
      treeOp -> right = NULL;
      // if hd is not null it becomes tree->right
      if (hd != NULL) { 
        treeOp -> right = hd -> node;
        pop(&hd);
      } else {
        printf("\nInvalid expression. Enter a valid postfix expression \n");
        while (hd != NULL) { 
          // clearing the stack
          clear(hd -> node);
          pop(&hd);
        }
        // clear the tree
        clear(treeOp); 
        return NULL;
      }
      // if hd is not null it becomes tree->left
      if (hd != NULL) { 
        treeOp -> left = hd -> node;
        pop(&hd);
      } else {
        printf("\nInvalid expression. Enter a valid postfix expression \n");
        // clearing the stack
        while (hd != NULL) { 
          clear(hd -> node);
          pop(&hd);
        }
        // clearing the tree if no more operands
        clear(treeOp); 
        return NULL;
      }
      // clear the stack and tree if operator does not have two operands
      if ((treeOp != NULL) && (treeOp -> left == NULL || treeOp -> right == NULL)) {
        printf("\nInvalid expression. Enter a valid postfix expression \n");
        // clearing the stack
        while (hd != NULL) {
          clear(hd -> node);
          pop(&hd);
        }
        // clearing the tree if no more operands
        clear(treeOp); 
        return NULL;
      } else {
        push(treeOp, &hd);
      }
    } else {
      printf("\nInvalid expression. Enter a valid postfix expression \n");
       // clearing the stack
      while (hd != NULL) {
        clear(hd -> node);
        pop(&hd);
      }
      return NULL;
    }
    ptr = strtok(NULL, " ");
  }
  // return the tree and clear the stack if stack is not empty
  if (hd != NULL && !isdigit(hd -> node -> token[0])) {
    root = hd -> node;
		
     // clearing the stack
    while (hd != NULL) {
      pop(&hd);
    }
    return root;
  } else {
    printf("\nInvalid expression. Enter a valid postfix expression \n");
    // clearing the stack
    while (hd != NULL) {
      clear(hd -> node);
      pop(&hd);
    }
    return NULL;
  }
  // clearing the stack
  while (hd != NULL) {
		clear(hd ->node);
    pop(&hd);
  }
  return NULL;
}
/********************************************************
 * Function:       evalExpression
 * Parameters:    C-style pass-by-value treeNode root and int val 
 * Return value:   int
 *******************************************************/
int evalExpression(treeNode* root, int val) {
	double leftVal = 0;
	double rightVal = 0;
	double result = 0;
	// if root node contains int
	if (checkDigit(root->token) == 1) {
		// return root int value
		return atoi(root->token);
	}
	// if root contains operator 
	if (isOperator(root->token) == 1) {
		// evaluate left subtree
		leftVal = evalExpression(root->left,val);
		// evaluate right subtree
		rightVal = evalExpression(root->right,val);
		// if root operator is +
		if (root->token[0] == '+') {
			// add left and right subtree value
			result = leftVal+rightVal;
		}
		// if root operator is -
		else if (root->token[0] == '-') {
			// subtract left and right subtree value
			result = leftVal - rightVal;
		}
		// if root operator is *
		else if (root->token[0] == '*') {
			// multiply left and right subtree value
			result = leftVal * rightVal;
		}
		// if root operator is /
		else if (root->token[0] == '/') {
			// divide left and right subtree value
			result = leftVal/rightVal;
		}
		// return result
		return result;
	}
  return result;
}