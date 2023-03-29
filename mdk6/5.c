#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//0 - прозрачный, 1 - непрозрачный

int main() {
    srand(time(NULL));
    int n = 3, i, j, k, gap_found = 0;
    printf("Введите размер куба (n): ");
    scanf("%d", &n);
    int*** cube = malloc(sizeof(int**) * n);
    for (i = 0; i < n; i ++) {
        cube[i] = malloc(sizeof(int*) * n);
    }
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j++) {
            cube[i][j] = malloc(sizeof(int) * n);
        }
    }
    // Инициализируем cube с помощью 0 (непрозрачный) и 1 (прозрачный)
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                cube[i][j][k] = rand() % 2;
            }
        }
    }
    printf("\n");
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                printf("%d, ", cube[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Проверка пробелов в каждом измерении
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j++) {
            gap_found = 0;
            for (k = 0; k < n; k++) {
                if (cube[i][j][k] == 1) {
                    gap_found = 1;
                    break;
                }
            }
            if(gap_found == 0){
                printf("В направлении x (%d, %d) обнаружен просвет\n", i, j);
            }
        }
    }
    for (i = 0; i < n; i ++) {
        for (k = 0; k < n; k++) {
            gap_found = 0;
            for (j = 0; j < n; j++) {
                if (cube[i][j][k] == 1) {
                    gap_found = 1;
                    break;
                }
            }
            if(gap_found == 0){
                printf("В направлении y (%d, %d) обнаружен просвет\n", i, j);
            }
        }
    }
    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
            gap_found = 0;
            for (i = 0; i < n; i ++) {
                if (cube[i][j][k] == 1) {
                    gap_found = 1;
                    break;
                }
            }
            if(gap_found == 0){
                printf("В направлении z (%d, %d) обнаружен просвет\n", i, j);
            }
        }
    }
    return 0;
}