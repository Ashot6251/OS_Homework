#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main() {
    int *grades;
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size. Please enter a positive number.\n");
        return 1;
    }

    grades = (int *)malloc(n * sizeof(int));

    if (grades == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the grades: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &grades[i]);
    }

    int highest = grades[0];
    int lowest = grades[0];

    for (int i = 0; i < n; i++) {
        if (grades[i] > highest)
            highest = grades[i];

        if (grades[i] < lowest)
            lowest = grades[i];
    }

    printf("Highest grade: %d\n", highest);
    printf("Lowest grade: %d\n", lowest);

    free(grades);
    grades = NULL;

    return 0;
}
