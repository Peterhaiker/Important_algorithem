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

void Preorder(Bina_tree*tree)
{
  if(NULL == tree)
    return;
  printf("%d ",tree->date);
  Preorder(tree->left);
  Preorder(tree->right);
}
