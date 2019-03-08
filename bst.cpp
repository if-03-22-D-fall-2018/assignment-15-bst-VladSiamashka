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
  if(bst!=0)sfree(bst);
}

int get_depth(Bst bst){
  if (bst==0)return 0;
  if (bst->right==0&&bst->right==0)return 1;
  return 2;
}

void add(Bst* bst, int value){
  Bst new_node=(Bst)malloc(sizeof(struct Node));
  new_node->value=value;
  new_node->left=0;
  if (bst==0) {
    (*bst)=new_node;
  }
  else{
    insert(value,bst,new_node);
  }
}

void insert(int value, Bst bst, Bst new_node){
  if (value<=bst->value) {
    if (bst->left==0) {
      bst->left=new_node;
      else{
        insert(value,bst->left,*new_node);
      }
    }
  }
  else{
    if (bst->right==0) {
      bst->right=new_node;
      else{
        insert(value,bst->right,*new_node);
      }
    }
}

int root_value(Bst bst){
if(bst!=0) return bst->value;
}

Bst left_subtree(Bst root){
  return 0;
}

Bst right_subtree(Bst root){
  return 0;
}

int traverse_pre_order(Bst bst, int *elements, int start){
  return 0;
}

int traverse_in_order(Bst bst, int *elements, int start){
  return 0;
}

int traverse_post_order(Bst bst, int *elements, int start){
  return 0;
}

bool are_equal(Bst bst1, Bst bst2){
  return false;
}

void most_left_longest_branch(Bst bst, Bst* branch){

}

int get_number_of_subtrees(Bst bst){
  return 0;
}
