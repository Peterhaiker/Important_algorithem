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
  printf("choice datetype[i/d/s(char or int/float or double/string)]:_\b");
  int datetype=getchar();
  while('\n'!=getchar())
    ;
  while(NULL==strchr("ids",datetype)){
    printf("invalid input,try again:_\b");
    datetype=getchar();
    while('\n'!=getchar())
      ;
  }

  int index=0;
  if('i'==datetype){
     int*arr=calloc(ARR_SIZE,sizeof(int));
    while(EOF!=scanf("%d",arr+index)){
      index++;
      if(index==ARR_SIZE){
        ARR_SIZE<<=1;
        arr=realloc(arr,ARR_SIZE*sizeof(int));
      }
    }
  }
  else if('d'==datetype){
     double*arr=calloc(ARR_SIZE,sizeof(double));
    while(EOF!=scanf("%lf",arr+index)){
      index++;
      if(index==ARR_SIZE){
        ARR_SIZE<<=1;
        arr=realloc(arr,ARR_SIZE*sizeof(double));
      }
    }
  }
  else{
     char**arr=calloc(ARR_SIZE,sizeof(char*));
    char ch[50]={'\0'};
    while(NULL!=fgets(ch,50,stdin)){
      arr[index++]=calloc(1,strlen(ch)+1);
      if(index==ARR_SIZE){
        ARR_SIZE<<=1;
        arr=realloc(arr,ARR_SIZE*sizeof(char**));
      }
    }
  }
  return 0;
}
