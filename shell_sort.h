#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <stdio.h>

#define STATIC_ALLOC_BUFFER     100

/**
 * Shell sorting algorithm.
 * 
 * @param ptr   Array pointer
 * @param count Items count of array
 * @param size  Size of a item
 * @param comp  Comparator funtion pointer (callback)
 * 
 * @note Comparator function returns 1 when first argument greater than second
 * one, -1 when first argument less than second one, 0 when they are equals. 
 */
void shell_sort(void *ptr, size_t count, size_t size, 
                int (*comp)(const void *, const void *));

/**
 * Algorithm implementation from https://www.geeksforgeeks.org/shellsort/
 * For testing.
 */
void shell_sort_test(short *array, int n);

#endif /* SHELL_SORT_H */