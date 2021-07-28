#include "btree.h"
#include "stack.h"

/********************************************************
 * Function:       pop
 * Parameters:     C-style pass-by-reference node pointer 
 * Return value:   none
 *******************************************************/
void pop(node** hd) {
  node* temp; 
  // Check for stack underflow
  if (*hd == NULL) { 
    return; 
    } else { 
      // Top assign into temp
      temp = *hd;
      // Assign second node to top 
      *hd = temp->next;
      // Destroy connection between
      // first and second 
      temp->next = NULL; 
      // Release memory of top node
      free(temp);
      }
}
/********************************************************
 * Function:       init
 * Parameters:     none 
 * Return value:   NULL
 *******************************************************/
node* init () {
  // initalizes head to NULL
  return NULL;
}
/********************************************************
 * Function:       isEmpty
 * Parameters:     C-style pass-by-value node pointer
 * Return value:   int
 *******************************************************/
int isEmpty(node* hd) {
  if (hd == NULL) {
    // if hd==NULL return 1 indicates NULL
    return 1;
  }
  // 0 indicates not empty
  return 0;
}
/********************************************************
 * Function:       printCommands
 * Parameters:     none 
 * Return value:   none
 *******************************************************/
void printCommands()
{
  // print all the commands the program offers
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("or any postfix mathematical expression using operators of *, /, +, -\n");
}
/********************************************************
 * Function:       clear
 * Parameters:     C-style pass-by-reference treeNode pointer
 * Return value:   none
 *******************************************************/
void clear(treeNode* root) {
  // if root is NULL it's empty
    if (root == NULL) {
        return;
        }
    // clear left subtree
    clear(root->left);
    // clear right subtree
    clear(root->right);
    // free the root
    free(root);
}
/********************************************************
 * Function:       push
 * Parameters:     C-style pass-by-value treeNode pointer and pass-by-reference node hd
 * Return value:   none
 *******************************************************/
void push(treeNode* root, node** hd) {
  // allocate new node
    node * pt = (node *) malloc (sizeof (node));
    // 
    pt->node = root;
    // ptr is new head
    pt->next = *hd;
    // update the head
    *hd = pt;
}