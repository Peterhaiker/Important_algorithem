/*
 * levelorder.c
 * Copyright (C) 2017-12-28 21:08 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include"Bina_tree.h"
#include<stdlib.h>
#include<assert.h>

void levelorder(Bina_tree*tree,int num)
{
  assert(tree);

  int QUEUE_SIZE=(num+1)/2;
  Bina_tree*tree_queue=calloc(QUEUE_SIZE,sizeof(Bina_tree));
  Bina_tree*p=tree;
  int pop_queue=-1;
  int push_queue=-1;

  tree_queue[++push_queue]=*p;
  printf("level_order:");
  while(pop_queue!=push_queue){
    pop_queue=(pop_queue+1)%QUEUE_SIZE;
    printf("%d ",tree_queue[pop_queue].date);
    if(NULL!=tree_queue[pop_queue].left){
      push_queue=(push_queue+1)%QUEUE_SIZE;
      tree_queue[push_queue]=*tree_queue[pop_queue].left;
    }
    if(NULL!=tree_queue[pop_queue].right){
      push_queue=(push_queue+1)%QUEUE_SIZE;
      tree_queue[push_queue]=*tree_queue[pop_queue].right;
    }
  }
  free(tree_queue);
  return;
}
