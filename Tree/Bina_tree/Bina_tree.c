/*
 * Bina_tree.c
 * Copyright (C) 2017-12-16 19:33 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:The main function to call all binary tree function
 */

#include "stdio.h"
#include "Bina_tree.h"
#include<stdlib.h>

int main(int argc,char*argv[])
{
  puts("please input all node date by level(^D to quit):");
  size_t node_num=20;
  int*node_info=malloc(sizeof(int)*node_num);
  int i=0;
  while(1 == scanf("%d",&node_info[i])){
    i++;
    if(20 == i){
      node_num+=20;
      node_info=realloc(node_info,node_num*sizeof(int));
    }
  }
  Bina_tree*tree=NULL;
  if((tree=Creat_bina_tree(node_info,i))!=NULL){
    puts("create success");
  }
  else{
    puts("create failed");
    return 0;
  }
  free(node_info);

  Preorder_nonrecusive(tree);
  putchar('\n');

  Inorder_nonrecusive(tree);
  putchar('\n');

  printf("Preorder:");
  Preorder_recusive(tree);
  putchar('\n');

  printf("Inorder:");
  Inorder_recusive(tree);
  putchar('\n');

  printf("Postorder:");
  Postorder_recusive(tree);
  putchar('\n');

  return 0;
}
