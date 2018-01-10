/*
 * sort.c
 * Copyright (C) 2018-01-01 17:11 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"sort.h"

int*get_input(int*input_num);

int main(int argc,char*argv[])
{
  int input_num;
  int*arr=get_input(&input_num);
  while(1){
    printf("****************************sort********************************\n");
    printf("a:bubble sort      b:insert sort      c:fold_half_insertion_sort\n");
    printf("d:reinput          e:quit\n");
    char choice;
    printf("please choice:_\b");
    while(!isalpha(choice=getchar()))
      printf("invalid input.try again:_\b");
    while('\n'!=getchar())
      ;
    switch(choice){
      case 'a':bubble_sort(arr,input_num);break;
      case 'b':insert_sort(arr,input_num);break;
      //case 'c':fold_half_insertion_sort(arr,input_num);break;
      case 'd':arr=get_input(&input_num);break;
      case 'e':exit(EXIT_SUCCESS);
      default:puts("invalid input.");
    }
  }
  return 0;
}
int*get_input(int*input_num)
{
  int*arr=calloc(10,sizeof(int));
  printf("please input:");
  for(*input_num=0;*input_num<ARR_SIZE&&(1==scanf("%d",arr+*input_num));(*input_num)++){
      //full stack
      if(*input_num==ARR_SIZE-1){
          ARR_SIZE<<=1;
          arr=realloc(arr,ARR_SIZE*sizeof(int));
      }
  }
  return arr;
}
