#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i ++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int M[8][5];
    int i, j;

    for (i = 0; i < 8; i ++) {
        for (j = 0; j < 5; j++) {
            M[i][j] = rand() % 30;
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 8; i ++) {
        BubleSort(M[i], 5);
    }

    printf("Отсортированная матрица:\n");
    for (i = 0; i < 8; i ++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}