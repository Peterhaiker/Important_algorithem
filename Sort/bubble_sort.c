/*
 * bubble_sort.c
 * Copyright (C) 2018-01-01 16:10 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include"sort.h"

bool unchanged=1;
void bubble_sort(int array[],size_t num)
{
  //if array is null,exit
  assert(array);
  //bubble sort begin
  printf("increase sort?(y/n):_\b");
  char increase;
  while(1!=scanf("%[yYnN]",&increase))
    printf("invalid input.try again:_\b");
  while('\n'!=getchar())
    ;
  if('y'==tolower(increase)){
    int max=0;
    for(int i=0;i<num;++i){
      for(int j=0;j<num-i-1;j++){
        if(array[j]>array[j+1]){
          max=array[j];
          array[j]=array[j+1];
          array[j+1]=max;
          unchanged=0;
        }
      }
      if(unchanged)
        break;
      unchanged=1;
    }
  }
  else{
    int min=0;
    for(int i=0;i<num;++i){
      for(int j=0;j<num-i-1;j++){
        if(array[j]<array[j+1]){
          min=array[j];
          array[j]=array[j+1];
          array[j+1]=min;
          unchanged=0;
        }
      }
      if(unchanged)
        break;
      unchanged=1;
    }
  }

  //output
  printf("bubble sort:");
  for(int i=0;i<num;++i)
    printf("%d ",array[i]);
  putchar('\n');
  return;
}
