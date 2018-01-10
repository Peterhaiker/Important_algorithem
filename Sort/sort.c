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
#include"sort.h"

int main(int argc,char*argv[])
{
  int*arr=calloc(10,sizeof(int));
  int input_num;
  printf("please input:");
  for(input_num=0;input_num<ARR_SIZE&&(1==scanf("%d",arr+input_num));++input_num){
      //full stack
      if(input_num==ARR_SIZE-1){
          ARR_SIZE<<=1;
          arr=realloc(arr,ARR_SIZE*sizeof(int));
      }
  }
  bubble_sort(arr,input_num);
  return 0;
}
