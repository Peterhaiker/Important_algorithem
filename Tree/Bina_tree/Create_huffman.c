/*
 * Create_huffman.c
 * Copyright (C) 2018-01-01 11:21 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Bina_tree.h"
#include"../../Sort/sort.h"

struct sorted_list{
  int num;
  Bina_tree*tree_node;
  struct sorted_list*next;
  struct sorted_list*prev;
}*sorted_list;

void Create_huffman(int*buff,size_t num)
{
  assert(buff);

  //sort the array by dichotomy
  bubble_sort(buff,num,1);
  //create a sorted list
  struct sorted_list*list_prev,*list_next;
  sorted_list=list_prev=list_next=calloc(1,sizeof(struct sorted_list));
  sorted_list->tree_node=calloc(1,sizeof(Bina_tree));
  list_next->num=buff[0];
  list_next->tree_node->date=buff[0];
  list_next->next=list_next->prev=NULL;
  for(int i=1;i<num;++i){
    list_next=calloc(1,sizeof(struct sorted_list));
    list_next->tree_node=calloc(1,sizeof(struct sorted_list));
    list_next->num=buff[i];
    list_next->tree_node->date=buff[i];
    list_prev->next=list_next;
    list_next->prev=list_prev;
    list_prev=list_next;
  }
  list_next->next=sorted_list;
  sorted_list->prev=list_next;
  //create huffman tree
  int tmp_num;
  int sum=num;
  Bina_tree*root=sorted_list->tree_node;//the root node of huffman tree
  struct sorted_list*tmp_node;
  list_prev=sorted_list;
  list_next=list_prev->next;
  while(1!=sum){
    tmp_num=list_prev->num+list_next->num;
    tmp_node=calloc(1,sizeof(struct sorted_list));
    tmp_node->num=tmp_num;
    //allocate a tree node space and assignment it
    //then connect the right and left subtree
    tmp_node->tree_node=calloc(1,sizeof(Bina_tree));
    tmp_node->tree_node->date=tmp_num;
    tmp_node->tree_node->right=list_prev->tree_node;
    tmp_node->tree_node->left=list_next->tree_node;
    //connect finished
    //if all node connected.then quit
    sum--;
    if(1==sum){
      root=tmp_node->tree_node;
      break;
    }
    //insert the new node to sorted list
    for(list_prev=list_next->next;list_prev!=sorted_list;list_prev=list_prev->next)
      if(list_prev->num>tmp_num)
        break;
    list_prev->prev->next=tmp_node;
    tmp_node->prev=list_prev->prev;
    tmp_node->next=list_prev;
    list_prev->prev=tmp_node;
    //insert finished
    //set the new first node
    list_next->next->prev=sorted_list->prev;
    sorted_list->prev->next=list_next->next;
    sorted_list=list_next->next;
    //right move the pre and next pointer
    list_prev=list_next->next;
    list_next=list_prev->next;
  }
  Preorder_recusive(root);
  return;
}
