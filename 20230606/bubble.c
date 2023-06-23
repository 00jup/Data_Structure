#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Initialize the flag as 0
        
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1; // Set the flag as 1 to indicate a swap occurred
            }
        }
        
        // If no swap occurred during the inner loop, the array is already sorted
        if (swapped == 0)
            break;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}