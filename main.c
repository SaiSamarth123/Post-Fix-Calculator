// Post-Fix-Calculator
// Author: Sai Patipati
// Description: Performs calculator functions of postfix notation using binary 
// search tree.
// 
#include "btree.h"
#include "stack.h"

int main(int argc, char const *argv[]) {
    
  char input[300];
	int result = 0;
	int isValid = 0;
  
  /* set up an infinite loop */
  while (1)
  {
		treeNode* node = NULL;
    fgets(input,300,stdin);
    int i = 0;
    /* remove the newline character from the input */
    while (input[i] != '\n' && input[i] != '\0')
    {
       i++;
    }
    input[i] = '\0';
    /* check if user enter q or Q to quit program */
    if ( (strcmp (input, "q") == 0) || (strcmp (input, "Q") == 0) )
    break;
    /* check if user enter ? to see command list */
    else if ( strcmp (input, "?") == 0) 
      printCommands();
      i = 0;
      /* user enters an expression */
      printf ("%s", input);
      // adds the postfix notation into a tree
      node = parseExpression(input); 
      if (node != NULL) {
        // infix
        printf("\nInfix notation: ");
        inOrder(node);
        // prefix
        printf("\nPrefix notation: "); 
        preOrder(node);
        // postfix
        printf("\nPostfix notation: ");
        postOrder(node);
        // calculates the postfix expression
        result = evalExpression(node,result); 
        printf("\n");
        printf("Expression result: %d\n", result);
				clear(node);
        }
  }
  printf ("\nGoodbye\n");
  return 0;
}