/*
 * sequence_search.c
 * Copyright (C) 2017-12-09 19:10 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include "stdio.h"

int sequence_search(int*buf,int num,int*value)
{
  for(int i=0;i<num;++i){
    if(*value==buf[i]){
      printf("buf[%d]=%d\n",i,buf[i]);
      return 0;
    }
  }
    return -1;
}
