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

static int STACK_SIZE=10;//for nonrecusive traverse

#include<stdbool.h>

//Binary tree structure,ignore element used in create binary tree and create clues binary tree.in which 0 represent child,1 represent before node or next node
typedef struct Bina_tree{
  int date;
  struct Bina_tree*left;
  bool l_ignore;
  struct Bina_tree*right;
  bool r_ignore;
}Bina_tree;

//structure for nonrecusive traverse tree
typedef struct{
  Bina_tree stack;
  bool l_visited;
  bool r_visited;
}stack;

//create a binary tree
Bina_tree *Creat_bina_tree(int*,size_t);
//travese binary tree
void Preorder_recusive(Bina_tree*);
void Inorder_recusive(Bina_tree*);
void Postorder_recusive(Bina_tree*);

void Preorder_nonrecusive(Bina_tree*);
void Inorder_nonrecusive(Bina_tree*);
void Postorder_nonrecusive(Bina_tree*);

void levelorder(Bina_tree*,int num);
//search a value
void Binary_search(Bina_tree*);

//create clues binary tree
void Create_preclue_bina_tree(Bina_tree*);
void Create_inclue_bina_tree(Bina_tree*);
void Create_Postclue_bina_tree(Bina_tree*);
void Create_levelclue_bina_tree(Bina_tree*);
//find precursor node or successor node in clues binary tree
void Find_prenode(Bina_tree*);
void Find_sucnode(Bina_tree*);
//inset a value in clues binary tree
void Insert_value_in_cluetree(Bina_tree*);
//leaf sum
void total_leaf(Bina_tree*);

//create huffman tree
void Create_huffman(int*,size_t);
#endif /* !BINA_TREE_H */
