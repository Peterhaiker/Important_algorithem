/*
 * Preorder.c
 * Copyright (C) 2017-12-16 19:55 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:The recusive version of preorder
 */

#include "stdio.h"
#include "Bina_tree.h"

void Preorder_recusive(Bina_tree*tree)
{
  if(NULL == tree)
    return;
  printf("%d ",tree->date);
  Preorder_recusive(tree->left);
  Preorder_recusive(tree->right);
}
