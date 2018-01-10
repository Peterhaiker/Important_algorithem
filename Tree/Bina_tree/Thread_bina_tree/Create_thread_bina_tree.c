/*
 * Create_thread_bina_tree.c
 * Copyright (C) 2018-01-01 10:42 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include<assert.h>
#include"../Bina_tree.h"

void Create_thread_bina_tree(Bina_tree*tree)
{
  assert(tree);

  stack*tree_stack=calloc(STACK_SIZE,sizeof(stack));
  int stack_index=-1;
  Bina_tree*p=tree;
  while(p||-1!=stack_index){
    
  }
  return 0;
}
