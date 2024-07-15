
// merge sort using DMA
//prog 11

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

static int count = 0;

void merge(int b[], int c[], int a[], int p, int q) {
    int i = 0, j = 0, k = 0;

    while (i < p && j < q) {
        count++;
        if (b[i] <= c[j])
            a[k++] = b[i++];
        else
            a[k++] = c[j++];
    }
    while (i < p)
        a[k++] = b[i++];
    while (j < q)
        a[k++] = c[j++];
}

void mergesort(int a[], float n) {
    int *b, *c, i,j=0, p, q;

    if (n > 1) {
        p = floor(n / 2);
        q = ceil(n / 2);
        b = (int*)malloc(p * sizeof(int));
        c = (int*)malloc(q * sizeof(int));

        for (i = 0;i < p;i++)
            b[i] = a[i];
        for (i = p;i < n;i++)
            c[j++] = a[i];

        mergesort(b, p);
        mergesort(c, q);
        merge(b, c, a, p, q);
        free(b);
        free(c);
    }
}
int main() {
    int* a, n, i;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    printf("Elements are\n");
    for (i = 0;i < n;i++)
        {
           a[i] = rand();
           printf("%d\t",a[i]);
       } 
    mergesort(a, n);
    printf("\nSorted element are\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\nBasic Operation Count=%d", count);
    free(a);
}

/*
Enter the value of N: 5
Elements are
41      18467   6334    26500   19169
Sorted element are
41	6334	18467	19169	26500

Basic Operation Count=6
*/
