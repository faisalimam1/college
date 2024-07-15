
// quicksort
//prg 10

#include <stdio.h>
#include <stdlib.h>

static int count = 0;

int partition(int a[], int l, int n) 
{
    int pivot = a[l], i = l, j = n + 1, temp;
    do 
    {
        do 
        {
            i++;
            count++;
        } while (i < n && a[i] < pivot);
        do 
        {
            j--;
            count++;
        } while (j > l && a[j] > pivot);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int a[], int l, int n) 
{
    int s;
    if (l < n) 
    {
        s = partition(a, l, n);
        quicksort(a, l, s - 1);
        quicksort(a, s+1, n);
    }
}

int main() 
{
    int a[10000], n, i;
    printf("Enter the size of array\n ");
    scanf("%d", &n);
    printf("Array elements are\n");
    for (i = 0;i < n;i++)
    {
        a[i] = rand();
        printf("%d\t", a[i]);
    }
    quicksort(a, 0, n-1);
    printf("\nSorted element are\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\nBasic Operation Count=%d", count);
    
}
/*
Enter the size of array
 5
Array elements are
41      18467   6334    26500   19169
Sorted element are
41      6334    18467   19169   26500
Basic Operation Count=13
*/
