/*
 * Bina_tree.c
 * Copyright (C) 2017-12-16 19:33 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:The main function to call all binary tree function
 */

#include<stdio.h>
#include"Bina_tree.h"
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
  if((tree=Creat_bina_tree(node_info,i))!=NULL)
    puts("create success");
  else{
    puts("create failed");
    return 0;
  }
  free(node_info);

  puts("***********************************menu**********************************");
  puts("1:Preorder_nonrecusive   2:Inorder_nonrecusive  3:Postorder_nonrecusive");
  puts("4:Preorder_recusive      5:Inorder_recusive     6:Postorder_recusive");
  puts("7:levelorder             8:Binary_search        9:total_leaf");
  puts("10:create huffman        10:quit");
  int choice;
  char str[3]={'\0'};
  while(1){
    printf("Please input:_\b");
    while(NULL==(fgets(str,3,stdin)))
      printf("Please input:_\b");
    choice=atoi(str);
    switch(choice){
      case 1:Preorder_nonrecusive(tree);putchar('\n');break;
      case 2:Inorder_nonrecusive(tree);putchar('\n');break;
      case 3:Postorder_nonrecusive(tree);putchar('\n');break;
      case 4:printf("Preorder:");Preorder_recusive(tree);putchar('\n');break;
      case 5:printf("Inorder:");Inorder_recusive(tree);putchar('\n');break;
      case 6:printf("Postorder");Postorder_recusive(tree);putchar('\n');break;
      case 7:printf("levelorder");levelorder(tree,i);putchar('\n');break;
      case 8:Binary_search(tree);putchar('\n');break;
      case 9:total_leaf(tree);putchar('\n');break;
      case 10:Create_huffman(node_info,i);putchar('\n');break;
      case 11:puts("bye");return 0;
      default:puts("invalid value");
    }
  }
}
