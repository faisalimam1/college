#include <stdio.h>

// Function to print the subset
void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

// Recursive function to find subsets
void findSubsets(int arr[], int n, int subset[], int subsetSize, int sum, int targetSum, int index) {
    // Base case: if the sum of the current subset is equal to the target sum
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    // If sum exceeds the target sum or if all elements have been considered, stop
    if (sum > targetSum || index == n) {
        return;
    }

    // Include the current element in the subset and recurse
    subset[subsetSize] = arr[index];
    findSubsets(arr, n, subset, subsetSize + 1, sum + arr[index], targetSum, index + 1);

    // Exclude the current element from the subset and recurse
    findSubsets(arr, n, subset, subsetSize, sum, targetSum, index + 1);
}

int main() {
    int n, d;

    // Read the size of the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int arr[n];
    // Read the elements of the set
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the target sum
    printf("Enter the target sum: ");
    scanf("%d", &d);

    int subset[n]; // Array to store the current subset

    printf("Subsets with sum %d:\n", d);
    findSubsets(arr, n, subset, 0, 0, d, 0);

    return 0;
}
