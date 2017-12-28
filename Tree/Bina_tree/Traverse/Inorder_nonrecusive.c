/*
 * Inorder_nonrecusive.c
 * Copyright (C) 2017-12-28 16:42 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include"../Bina_tree.h"
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

void Inorder_nonrecusive(Bina_tree*tree)
{
  assert(tree);

  stack*tree_stack=calloc(STACK_SIZE,sizeof(stack));
  int tree_stack_index=-1;
  Bina_tree*p=tree;

  printf("Inorder_nonrecusive:");
  while(p||-1!=tree_stack_index){
    //viist new node
    while(p){
      //expand stack size
      if(tree_stack_index+1==STACK_SIZE){
        STACK_SIZE<<=1;
        tree_stack=realloc(tree_stack,STACK_SIZE*sizeof(stack));
      }
      tree_stack[++tree_stack_index].stack=*p;
      tree_stack[tree_stack_index].r_visited=0;
      tree_stack[tree_stack_index].l_visited=1;
      p=p->left;
    }
    //back
    p=&tree_stack[tree_stack_index].stack;
    while(tree_stack[tree_stack_index].r_visited&&tree_stack_index!=0)
      p=&tree_stack[--tree_stack_index].stack;
    if(tree_stack[tree_stack_index].r_visited&&0==tree_stack_index)
      break;
    printf("%d ",p->date);
    tree_stack[tree_stack_index].r_visited=1;
    p=p->right;
  }
  return;
}
