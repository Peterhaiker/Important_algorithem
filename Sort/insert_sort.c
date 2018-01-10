/* insert_sort.c
 * Copyright (C) 2018-01-10 16:46 
 * author:peterhaiker
 * email:vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include"sort.h"

void insert_sort(int array[],size_t num)
{
  assert(array);

  char increase;
  printf("increase sort?(y/n):_\b");
  while(1!=scanf("%[yYnN]",&increase))
    printf("invalid input.try again:_\b");
  while('\n'!=getchar())
    ;
  if('y'==tolower(increase)){
    int tmp_min,tmp_index;
    for(int i=0;i<num;++i){
      for(int j=0;j<i;j++){
        if(array[j]>=array[i]){
          tmp_min=array[i];
          for(tmp_index=i-1;tmp_index!=j;tmp_index--)
            array[tmp_index+1]=array[tmp_index];
          array[tmp_index+1]=array[tmp_index];
          array[tmp_index]=tmp_min;
        }
      }
    }
  }
  else{
    int tmp_max,tmp_index;
    for(int i=0;i<num;++i){
      for(int j=0;j<i;j++){
        if(array[j]<=array[i]){
          tmp_max=array[i];
          for(tmp_index=i-1;tmp_index!=j;tmp_index--)
            array[tmp_index+1]=array[tmp_index];
          array[tmp_index+1]=array[tmp_index];
          array[tmp_index]=tmp_max;
        }
      }
    }
  }
  printf("insert sort:");
  for(int i=0;i<num;++i)
    printf("%d ",array[i]);
  return;
}
