/*
 * KMP_next.c
 * Copyright (C) 2017-12-06 18:48 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:当你使用KMP字符串比较算法时，需要先构造出匹配串的next数组，原串和匹配串都是从0开始而不是1
 */

#include "stdio.h"
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main(int argc,char*argv[])
{
  errno=0;
  if(2!=argc){
    puts("usage:./KMP_next <string>");
    return errno;
  }
  //allocate space for next string
  
  int *next=calloc(strlen(argv[1]),sizeof(int));
  next[0]=-1;
  printf("next:%d",next[0]);
  //j is the value of next,i is index of string
  for(int i=1,j=next[0],max=strlen(argv[1]);i<max;){
    if(j==-1||argv[1][i-1]==argv[1][j]){
      ++j;
      next[i]=j;//equal
      printf("%d",j);
      ++i;
    }
    else
      j=next[j];
  }
  putchar('\n');
  return 0;
}
