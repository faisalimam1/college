//selection sort
#include<stdio.h>
#include<stdlib.h>

int count = 0;

void SelectionSort(int arr[], int n) 
{
    int i, j, pos, temp;
    for (i = 0; i < n - 1; i++) 
    {
        pos = i;
        for (j = i + 1; j < n; j++) 
        {
            count++;
            if (arr[j] < arr[pos]) 
            {
                pos = j;
            }
        
        
            temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;
        }
    }
}

void main() 
{
    int n, arr[1000], i;
    printf("Enter the size of array\n ");
    scanf("%d", &n);
    printf("Array elements are\n");
    for (i = 0;i < n;i++)
    {
        arr[i]=rand();
        printf("%d\t ", arr[i]);
    }
    SelectionSort(arr,n);
    printf("\nSorted Elements are\n");
    for (i = 0;i < n;i++)
        printf("%d\t", arr[i]);
    printf("\nBasic Operation Count= %d\n", count);


}
