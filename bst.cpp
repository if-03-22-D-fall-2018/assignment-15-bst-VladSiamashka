/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/


#include "bst.h"
#include <stdlib.h>
#include "general.h"

struct Node{
  int value;
  Bst left;
  Bst right;
};

Bst new_bst()
{
  return 0;
}

void delete_bst(Bst bst){
  if (bst!=0) {
    delete_bst(bst->right);
    delete_bst(bst->left);
    sfree(bst);
  }
}


int get_depth(Bst bst){
  if (bst==0)return 0;
  if (bst->right==0&&bst->left==0)return 1;
  if (get_depth(left_subtree(bst))>get_depth(right_subtree(bst)))return 1+get_depth(left_subtree(bst));
  return 1+get_depth(right_subtree(bst));
}

void add(Bst* bst, int value){
  Bst new_node=(Bst)malloc(sizeof(struct Node));
  new_node->value=value;
  new_node->left=0;
  new_node->right=0;

  if (*bst==0) {
    (*bst)=new_node;
  }

  else if (value<=(*bst)->value) {
    if ((*bst)->left==0) {
      (*bst)->left=new_node;
      }
      else{
        add(&(*bst)->left,value);
      }
  }
  else if(value>(*bst)->value){
    if ((*bst)->right==0) {
      (*bst)->right=new_node;
      }
      else{
        add(&(*bst)->right,value);
      }
    }
}



int root_value(Bst bst){
  if(bst!=0) return bst->value;
  return 0;
}

Bst left_subtree(Bst root){
  return root->left;
}

Bst right_subtree(Bst root){
  return root->right;
}

int traverse_pre_order(Bst bst, int *elements, int start){
  if(bst != 0) {
    elements[start] = bst->value;
    start+=1;
    start = traverse_pre_order(bst->left, elements, start);
    start = traverse_pre_order(bst->right, elements, start);
   }
   return start;
}

/**
*** Traverses the BST depth first by first traversing the left subtree, then adding the root,
*** then traversing the right subtree.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_in_order(Bst bst, int *elements, int start){
  if (bst!=0) {
    start=traverse_in_order(bst->left, elements, start);
    elements[start]=bst->value;
    start+=1;
    start=traverse_in_order(bst->right, elements, start);
  }
  return start;
}

/**
*** Traverses the BST depth first by first traversing the left subtree, then traversing the right
*** subtree and finally adding the root.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_post_order(Bst bst, int *elements, int start){
  if (bst!=0) {
    if(bst->left != 0){
      start = traverse_post_order(bst->left, elements, start);
    }
    if(bst->right != 0){
      start = traverse_post_order(bst->right, elements, start);
    }
    elements[start]=bst->value;
    start+=1;
  }
  return start;
}

bool are_equal(Bst bst1, Bst bst2){
  return false;
}

void most_left_longest_branch(Bst bst, Bst* branch){

}

int get_number_of_subtrees(Bst bst){
  return 0;
}
