/*
 * Create_huffman.c
 * Copyright (C) 2018-01-01 11:21 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Bina_tree.h"
#include"../../Sort/sort.h"

struct sorted_list{
  Bina_tree*pnode;
  struct sorted_list*previous;
  struct sorted_list*next;
}*sorted_list;

void Create_huffman(int*buff,size_t num)
{
  assert(buff);

  //sort the array by dichotomy
  bubble_sort(&buff,num,1);

  struct sorted_list*one,*two;
  for(int i=0;i<num;++i){
    two=one;
    one=calloc(1,sizeof(struct sorted_list));
    one->pnode=calloc(1,sizeof(Bina_tree));
    one->pnode->date=buff[i];
    //first node
    if(0==i){
      sorted_list=one;
      sorted_list->previous=sorted_list->next=NULL;
    }
    //last node
    else if(num-1==i){
      sorted_list->previous=one;
      one->next=sorted_list;
      one->previous=two;
      two->next=one;
    }
    else{
      two->next=one;
      one->previous=two;
      one->next=NULL;
    }
  }
  //create huffman tree
  struct sorted_list*p,*p1,*p2,*new_ele;
  Bina_tree*root=NULL;
  p1=sorted_list;
  p2=sorted_list->next;
  int stack_index=0;
  int temp_num=0;
  while(num-1!=stack_index){
    temp_num=p1->pnode->date+p2->pnode->date;
    new_ele=calloc(1,sizeof(struct sorted_list));
    new_ele->pnode=calloc(1,sizeof(Bina_tree));
    new_ele->pnode->date=temp_num;
    new_ele->pnode->left=p1->pnode;
    new_ele->pnode->right=p2->pnode;
    for(p=p2->next;p!=sorted_list;p=p->next)
      if(temp_num<=p->pnode->date){
        new_ele->next=p;
        p->previous=new_ele;
        break;
      }
    if(p==sorted_list){
      p=sorted_list->previous;
      p->next=new_ele;
      new_ele->previous=p;
      new_ele->next=sorted_list;
      sorted_list->previous=new_ele;
    }
    stack_index++;
    p1=p2;
    p2=p2->next;
    if(num-1==stack_index)
      root=new_ele->pnode;
  }
  Preorder_recusive(root);
  return;
}
