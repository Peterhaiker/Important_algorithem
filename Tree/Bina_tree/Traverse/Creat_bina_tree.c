/*
 * Creat_bina_tree.c
 * Copyright (C) 2017-12-16 18:00 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include<stdio.h>
#include"../Bina_tree.h"
#include<stdlib.h>
#include<assert.h>

Bina_tree*Creat_bina_tree(int*buf,size_t num)
{
  assert(buf);
  //allocate a queue
  int max_leaf=(num+1)/2;
  Bina_tree *tree_queue[max_leaf];
  int visit_index=0;//The index of tree_queue when extract a node
  int add_index=0;

  Bina_tree*p=NULL,*q=NULL;
  Bina_tree*root=p;
  for(int i=0;i<num;++i){
    if(buf[i]!=0){
      //allocate space and assignment
      p=(Bina_tree*)malloc(sizeof(Bina_tree));
      p->l_ignore=p->r_ignore=0;
      p->date=buf[i];
      p->left=p->right=NULL;

      tree_queue[add_index%max_leaf]=p;//push the new node to the queue
      add_index++;
      if(1==add_index)//root node
        root=p;
      else{//not root node
        q=tree_queue[visit_index%max_leaf];
        if(0==q->l_ignore){
          q->left=p;//update the left child
          q->l_ignore=1;//update the left pointer state
        }//if
        else{
          q->right=p;//update the right child
          q->r_ignore=1;//update the right pointer state
          visit_index++;//the node pop to the queue
        }//else
      }//else
    }//if
    else{//ignore the node
      q=tree_queue[visit_index%max_leaf];
      if(0 == q->l_ignore)
        q->l_ignore=1;
      else{
        q->r_ignore=1;
        visit_index++;
      }//else
    }//else
  }//for
  return root;
}
