/*
 * bubble_sort.c
 * Copyright (C) 2018-01-01 16:10 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include"sort.h"

bool unchanged=1;
void bubble_sort(int array[],size_t num)
{
  //if array is null,exit
  assert(array);

  int max;
  //backup the array
  int*arr_cpy=calloc(num,sizeof(int));
  for(int i=0;i<num;++i)
      arr_cpy[i]=array[i];

  //bubble sort begin
  for(int i=0;i<num;++i){
    for(int j=0;j<num-i-1;j++){
      if(arr_cpy[j]>arr_cpy[j+1]){
          max=arr_cpy[j];
          arr_cpy[j]=arr_cpy[j+1];
          arr_cpy[j+1]=max;
          unchanged=0;
      }
    }
    if(unchanged)
      break;
    unchanged=1;
  }
  
  //output
  printf("bubble sort:");
  for(int i=0;i<num;++i)
    printf("%d ",arr_cpy[i]);
  putchar('\n');
  return;
}
