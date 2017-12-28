/*
 * Inorder_recusive.c
 * Copyright (C) 2017-12-16 22:31 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:the recusive version of preorder
 */

#include "stdio.h"
#include "Bina_tree.h"

void Inorder_recusive(Bina_tree*tree)
{
  if(NULL == tree)
    return;
  Inorder_recusive(tree->left);
  printf("%d ",tree->date);
  Inorder_recusive(tree->right);
}
