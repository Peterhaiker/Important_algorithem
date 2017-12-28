/*
 * Postorder_nonrecusive.c
 * Copyright (C) 2017-12-28 20:40 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include"Bina_tree.h"
#include<assert.h>
#include<stdlib.h>

void Postorder_nonrecusive(Bina_tree*tree)
{
  assert(tree);

  stack*tree_stack=calloc(STACK_SIZE,sizeof(stack));
  int tree_stack_index=-1;
  Bina_tree*p=tree;

  printf("Postorder_nonrecusive:");
  while(p||-1!=tree_stack_index){
    if(p){
      //stack overflow
      if(tree_stack_index+1==STACK_SIZE){
        STACK_SIZE<<=1;
        tree_stack=realloc(tree_stack,STACK_SIZE*sizeof(stack));
      }
      //push stack
      tree_stack[++tree_stack_index].stack=*p;
      tree_stack[tree_stack_index].l_visited=1;
      tree_stack[tree_stack_index].r_visited=0;
      p=p->left;
    }
    else{
      p=&tree_stack[tree_stack_index].stack;
      while(tree_stack[tree_stack_index].r_visited&&0!=tree_stack_index){
        printf("%d ",p->date);
        p=&tree_stack[--tree_stack_index].stack;
      }
      if(tree_stack[tree_stack_index].r_visited&&0==tree_stack_index){
        printf("%d ",p->date);
        break;
      }
      p=p->right;
      tree_stack[tree_stack_index].r_visited=1;
    }
  }
  free(tree_stack);
  return;
}
