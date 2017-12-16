/*
 * Creat_bina_tree.c
 * Copyright (C) 2017-12-16 18:00 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include "stdio.h"
#include"Bina_tree.h"
#include<stdlib.h>
#include<errno.h>

Bina_tree*Creat_bina_tree(int*buf,size_t num)
{
  if(NULL==buf){
    perror("you must provide the node date");
    return NULL;
  }
  //allocate a queue
  int max_leaf=(num+1)/2;
  Bina_tree *tree_queue[max_leaf];
  int j=0;//The index of tree_queue when extract a node

  Bina_tree*p=NULL,*q=NULL;
  Bina_tree*tree=p;
  for(int i=0;i<num;++i){
    if(buf[i]!=0){
      //allocate space and assignmend
      p=(Bina_tree*)malloc(sizeof(Bina_tree));
      p->l_ignore=p->r_ignore=0;
      p->date=buf[i];
      p->left=p->right=NULL;

      if(0==i){//root node
        tree_queue[0]=p;
        tree=p;
      }
      else{//not root node
        q=tree_queue[j%max_leaf];
        if(0 == q->l_ignore){
          q->left=p;//update the left child
          q->l_ignore=1;//update the left pointer state
        }//if
        else{
          q->right=p;//update the right child
          q->r_ignore=1;//update the right pointer state
          j++;//the node pop to the queue
        }//else
        tree_queue[i%max_leaf]=p;//push the new node to the queue
      }//else
    }//if
    else{//ignore the node
      q=tree_queue[j%max_leaf];
      if(0 == q->l_ignore)
        q->l_ignore=1;
      else{
        q->r_ignore=1;
        j++;
      }//else
    }//else
  }//for
  return tree;
}
