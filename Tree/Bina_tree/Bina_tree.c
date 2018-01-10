/*
 * Bina_tree.c
 * Copyright (C) 2017-12-16 19:33 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:The main function to call all binary tree function
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"Bina_tree.h"

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

  while(1){
    puts("***********************************menu**********************************");
    puts("a:Preorder_nonrecusive   b:Inorder_nonrecusive  c:Postorder_nonrecusive");
    puts("d:Preorder_recusive      e:Inorder_recusive     f:Postorder_recusive");
    puts("g:levelorder             h:Binary_search        i:total_leaf");
    puts("j:create huffman         k:quit");
    //get input from stdin
    char choice;
    printf("Please choice:_\b");
    while(!isalpha(choice=getchar()))
      printf("invalied input.choice again:_\b");
    //drop all useless input in inputstring
    while('\n'!=getchar())
      ;
    switch(tolower(choice)){
      case 'a':Preorder_nonrecusive(tree);putchar('\n');break;
      case 'b':Inorder_nonrecusive(tree);putchar('\n');break;
      case 'c':Postorder_nonrecusive(tree);putchar('\n');break;
      case 'd':printf("Preorder:");Preorder_recusive(tree);putchar('\n');break;
      case 'e':printf("Inorder:");Inorder_recusive(tree);putchar('\n');break;
      case 'f':printf("Postorder");Postorder_recusive(tree);putchar('\n');break;
      case 'g':printf("levelorder");levelorder(tree,i);putchar('\n');break;
      case 'h':Binary_search(tree);putchar('\n');break;
      case 'i':total_leaf(tree);putchar('\n');break;
      case 'j':Create_huffman(node_info,i);putchar('\n');break;
      case 'k':puts("bye");return 0;
      default:puts("invalid value");
    }
    }
}
