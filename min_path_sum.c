#include <stdio.h>

int main() {
    int arr[4][4] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int i, j=0, sum = arr[0][0];
    printf("Path: %d \n", arr[0][0]);
    for (i = 0; i < 3; i++) {
        if (arr[i + 1][j] < arr[i + 1][j + 1]) {
            sum += arr[i + 1][j];
            printf("%d \n", arr[i + 1][j]);
        } else {
            sum += arr[i + 1][j + 1];
            printf("%d \n", arr[i + 1][j + 1]);
            j++;
        }
    }

    printf("Minimum path sum: %d", sum);
    return 0;
}