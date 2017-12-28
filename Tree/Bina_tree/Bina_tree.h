/*
 * Bina_tree.h
 * Copyright (C) 2017-12-16 18:10
 * author  Peterhaiker 
 * email  <vim.memory@gmail.com>
 *
 * description:
 */

#ifndef BINA_TREE_H
#define BINA_TREE_H

#include<stdbool.h>

typedef struct Bina_tree{
  int date;
  struct Bina_tree*left;
  bool l_ignore;
  struct Bina_tree*right;
  bool r_ignore;
}Bina_tree;

Bina_tree *Creat_bina_tree(int*,size_t);
void Preorder_recusive(Bina_tree*);
void Inorder_recusive(Bina_tree*);
void Postorder_recusive(Bina_tree*);

void Preorder_nonrecusive(Bina_tree*);
void Inorder_nonrecusive(Bina_tree*);
void Postorder_nonrecusive(Bina_tree*);
#endif /* !BINA_TREE_H */
