/*
 * Postorder.c
 * Copyright (C) 2017-12-16 23:06 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:The recusive version of postorder
 */

#include "stdio.h"
#include"Bina_tree.h"

void Postorder_recusive(Bina_tree*tree)
{
  if(tree==NULL)
    return;
  Postorder_recusive(tree->left);
  Postorder_recusive(tree->right);
  printf("%d ",tree->date);
}
