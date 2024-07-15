//selection sort
//prg 9

#include<stdio.h>
#include<stdlib.h>

static int count = 0;

void SelectionSort(int arr[], int n) 
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) 
    {
        min = i;
        for (j = i + 1; j < n; j++) 
        {
            count++;
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        
        
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void main() 
{
    int n, arr[5000], i;
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

/*
Enter the size of array
 5
Array elements are
41       18467   6334    26500   19169
Sorted Elements are
41      6334    18467   19169   26500
Basic Operation Count= 10
*/
