/*
 * sort.h
 * Copyright (C) 2018-01-01 12:20
 * author  Peterhaiker 
 * email  <vim.memory@gmail.com>
 *
 * description:
 */

#ifndef SORT_H
#define SORT_H

#include<stdbool.h>

static int ARR_SIZE=10;
//the type number represent the sort of string,int or double etc
void bubble_sort(int array[],size_t num);
void insert_sort(int array[],size_t num);
void fold_half_insertion_sort(int array[],size_t num);

#endif /* !SORT_H */
