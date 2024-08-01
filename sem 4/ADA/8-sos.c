#include <stdio.h>

void printSubset(int subset[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void findSubsets(int arr[], int n, int subset[], int subsetSize, int sum, int targetSum, int index) 
{

    if (sum == targetSum) 
    {
        printSubset(subset, subsetSize);
        return;
    }
    if (sum > targetSum || index == n) 
    {
        return;
    }

    subset[subsetSize] = arr[index];
    findSubsets(arr, n, subset, subsetSize + 1, sum + arr[index], targetSum, index + 1);

    findSubsets(arr, n, subset, subsetSize, sum, targetSum, index + 1);
}

int main() 
{
    int n, d;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &d);

    int subset[n]; 

    printf("Subsets with sum %d:\n", d);
    findSubsets(arr, n, subset, 0, 0, d, 0);

    return 0;
}
