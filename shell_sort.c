// #include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "shell_sort.h"

void shell_sort(void *ptr, size_t count, size_t size, 
                int (*comp)(const void *, const void *))
{
    uint8_t tmp[STATIC_ALLOC_BUFFER]; /* static allocated */
    uint8_t *item_a, *item_b;

    for (size_t interval = count / 2; interval > 0; interval /= 2) {
        for (size_t i = interval; i < count; i++) {
            item_a = &((uint8_t *)ptr)[i * size];
            memcpy((void *)tmp, (void *)item_a, size);
            size_t j = i;
            for (; j >= interval; j -= interval) {
                item_a = &((uint8_t *)ptr)[j * size];
                item_b = &((uint8_t *)ptr)[(j - interval) * size];
                if (comp((void *)item_b, (void *)tmp) > 0)
                    memcpy((void *)item_a, (void *)item_b, size);
                else
                    break;
            }
            item_a = &((uint8_t *)ptr)[j * size];
            memcpy((void *)item_a, (void *)tmp, size);
        }
    }
}

void shell_sort_test(short array[], int n) 
{
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (size_t interval = n / 2; interval > 0; interval /= 2) {
        // printf("interval: %u\n", interval);
        for (size_t i = interval; i < n; i++) {
            // printf("i = %u | ", i);
            // print_array(array, n);
            int temp = array[i];
            size_t j = i;
            // for (; (j >= interval) && (array[j - interval] > temp); j -= interval) {
            for (; j >= interval; j -= interval) {
                // printf("\tj = %u | ", j);
                // print_array(array, n);
                if ((array[j - interval] > temp)) {
                    array[j] = array[j - interval];
                    // printf("\t+ ");
                    // print_array(array, n);
                } else 
                    break;
            }
            array[j] = temp;
        }
    }
}
