#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "shell_sort.h"

#define SIZEOF_ARRAY(arr) (sizeof(arr) / sizeof(arr[0]))

struct n1_n2 {
    unsigned short n1;
    unsigned short n2;
};

void print_array(short *arr, size_t len)
{
    for(size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int cmp_1(void *a, void *b)
{
    unsigned short a_n1 = ((struct n1_n2 *)a)->n1;
    unsigned short b_n1 = ((struct n1_n2 *)b)->n1;

    return ((a_n1 > b_n1) ? 1 : 0);
}

int cmp_n(const void *a, const void *b)
{
    struct n1_n2 *ap = (struct n1_n2 *)a;
    struct n1_n2 *bp = (struct n1_n2 *)b;

    if (ap->n1 > bp->n1)
        return 1;
    else if (ap->n1 < bp->n1)
        return -1;
    else if (ap->n2 > bp->n2)
        return 1;
    else if (ap->n2 < bp->n2)
        return -1;
        
    return 0;
}

int main()
{
    srand(time(NULL));

    struct n1_n2 mar[20];
    const size_t mar_size = SIZEOF_ARRAY(mar);

    /* rand */
    for (size_t i = 0; i < mar_size; i++) {
        mar[i].n1 = rand()%10 ;
        mar[i].n2 = rand()%100 + 101;
    }
    /* print */
    for (size_t i = 0; i < mar_size; i++) {
        printf("%u %u\n", mar[i].n1, mar[i].n2);
    }
    printf("\n");
    /* sort 1*/
    // qsort(mar, mar_size, sizeof(struct n1_n2), &cmp_n);
    shell_sort(mar, mar_size, sizeof(struct n1_n2), &cmp_n);
    /* print */
    for (size_t i = 0; i < mar_size; i++) {
        printf("%u %u\n", mar[i].n1, mar[i].n2);
    }

    return 0;
}
