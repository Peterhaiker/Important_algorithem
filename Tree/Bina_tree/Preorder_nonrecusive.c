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

int STACK_SIZE=10;
typedef struct{
  Bina_tree stack;
  bool l_visited;
  bool r_visited;
}stack;

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
        tree_stack=realloc(tree_stack,STACK_SIZE);
      }
      tree_stack[++tree_stack_index].stack=*p;
      //full stack
      tree_stack[tree_stack_index].l_visited=1;
      p=p->left;
    }
    else{
      p=&tree_stack[tree_stack_index].stack;
      while(tree_stack[tree_stack_index].r_visited){
        if(0==tree_stack_index)
          break;
        else
          p=&tree_stack[--tree_stack_index].stack;
      }
      if(0==tree_stack_index&&tree_stack[tree_stack_index].r_visited==1)
        break;
      tree_stack[tree_stack_index].r_visited=1;
      p=p->right;
    }
  }
  free(tree_stack);
  return;
}
