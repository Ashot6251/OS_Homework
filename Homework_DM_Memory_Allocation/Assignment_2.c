#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size. Please enter a positive number.\n");
        return 1;
    }

    arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Array after calloc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    float average = (float)sum / n;
    printf("Average of the array: %.1f\n", average);

    free(arr);
    arr = NULL;

    return 0;
}
