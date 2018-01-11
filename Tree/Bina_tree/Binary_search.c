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

void Binary_search(Bina_tree*tree)
{
  //if tree==NULL,then quit
  assert(tree);
  //tree!=NULL,then allocate a stack to store
  stack*tree_stack;
  tree_stack=calloc(STACK_SIZE,sizeof(stack));
  int tree_stack_index=-1;
  Bina_tree*p=tree;

  printf("please input a value you want to search:_\b");
  int num=-1;
  while(1!=scanf("%d",&num)){
    while('\n'!=getchar())
      ;
    printf("try again:_\b");
  }
  while('\n'!=getchar())
    ;

  while(p||-1!=tree_stack_index){
    while(p){
      if(p->date==num){
        puts("found");
        return;
      }
      //full stack
      if(tree_stack_index==STACK_SIZE-1){
        STACK_SIZE<<=1;//STACK_SIZE*2
        tree_stack=realloc(tree_stack,STACK_SIZE*sizeof(stack));
      }
      tree_stack[++tree_stack_index].stack=*p;
      tree_stack[tree_stack_index].r_visited=0;
      tree_stack[tree_stack_index].l_visited=1;
      p=p->left;
    }
    p=&tree_stack[tree_stack_index].stack;
    while(tree_stack[tree_stack_index].r_visited&&0!=tree_stack_index)
        p=&tree_stack[--tree_stack_index].stack;
    if(tree_stack[tree_stack_index].r_visited&&0==tree_stack_index)
        break;
    tree_stack[tree_stack_index].r_visited=1;
    p=p->right;
  }
  free(tree_stack);
  puts("not found");
  return;
}
