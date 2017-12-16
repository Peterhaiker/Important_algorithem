/*
 * Inorder.c
 * Copyright (C) 2017-12-16 22:31 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include "stdio.h"
#include "Bina_tree.h"

void Inorder(Bina_tree*tree)
{
  if(NULL == tree)
    return;
  Inorder(tree->left);
  printf("%d ",tree->date);
  Inorder(tree->right);
}
