/*
 * bubble_sort.c
 * Copyright (C) 2018-01-01 16:10 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include <stdio.h>
#include<stdbool.h>
#include<assert.h>
#include"sort.h"

#define MAX_SIZE(X1,X2) strlen(X1)>strlen(X2)?strlen(X1):strlen(X2)

void bubble_sort(void*array[],size_t num)
{
  //choice datetype
  printf("datetype[i/d/s(int/float or double/string)]:_b\n");
  char datetype=getchar();
  while('\n'!=getchar())
    ;
  while(NULL==strchr("ids",datetype)){
    printf("invalid input,try again:_\b");
    datetype=getchar();
    while('\n'!=getchar())
      ;
  }
  //choice sorttype
  printf("sortype[i/d(increment/decreasing)]:_\b");
  char sorttype=getchar();
  while('\n'!=getchar())
    ;
  while(NULL==strchr("id",sorttype)){
    printf("invalid input,try again:_\b");
    sorttype=getchar();
    while('\n'!=getchar())
      ;
  }

  //universal setting for datetype
  bool isstr=0;
  if('i'==datetype){
    int*arr=array[0];
    int tmp;
    size_t SIZE=sizeof(int);
  }
  else if('d'==datetype){
    double*arr=array[0];
    double tmp;
    size_t SIZE=sizeof(double);
  }
  else{
    char**arr=array;
    char*tmp;
    isstr=1;
  }

  //universal setting for sorttype
  bool increment=1;
  if('d'==sorttype)
    increment=0;

  //bubble sort
  for(int i=0;i<num;++i){
    for(j=i;j<num-1;j++){
      switch(memcmp(arr[j],arr[j+1],isstr?MAX_SIZE(arr[j],arr[j+1]):SIZE)){
      case 1://increment sort
        if(increment){
          tmp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=tmp;
        }
      case -1://decreasing sort
        if(0==increment){
          tmp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=tmp;
        }
      }
    }
  }
  for(int i=0;i<num;++i){
    if(datetype=='i')
      printf("%d ",arr[i]);
    else if(datetype=='d')
      printf("%f ",arr[i]);
    else
      puts(arr[i]);
  }
  putchar('\n');
  return;
}
