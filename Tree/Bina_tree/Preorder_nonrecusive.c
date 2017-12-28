/*
 * Preorder_nonrecusive.c
 * Copyright (C) 2017-12-28 11:39 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include<stdlib.h>
#include"Bina_tree.h"
#include<assert.h>
#include<stdbool.h>

void Preorder_nonrecusive(Bina_tree*tree)
{
  //if tree==NULL,then quit
  assert(tree);
  //tree!=NULL,then allocate a stack to store
  stack*tree_stack;
  tree_stack=calloc(STACK_SIZE,sizeof(stack));
  int tree_stack_index=-1;
  Bina_tree*p=tree;
  printf("Preorder_nonrecusive:");
  while(p||-1!=tree_stack_index){
    if(p){
      printf("%d ",p->date);
      if(tree_stack_index==STACK_SIZE-1){
        STACK_SIZE<<=1;//STACK_SIZE*2
        tree_stack=realloc(tree_stack,STACK_SIZE*sizeof(stack));
      }
      tree_stack[++tree_stack_index].stack=*p;
      //full stack
      tree_stack[tree_stack_index].l_visited=1;
      p=p->left;
    }
    else{
      p=&tree_stack[tree_stack_index].stack;
      while(tree_stack[tree_stack_index].r_visited&&0!=tree_stack_index)
          p=&tree_stack[--tree_stack_index].stack;
      if(tree_stack[tree_stack_index].r_visited&&0==tree_stack_index)
          break;
      tree_stack[tree_stack_index].r_visited=1;
      p=p->right;
    }
  }
  free(tree_stack);
  return;
}
