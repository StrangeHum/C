#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void SwapMaxValues (int A [], int lenA, int B [][9], int lenB) {
    //Находим индекс максимального элемента в массиве A
    int maxInd = 0;
    int countMaxVal = 0;
    for (int i = 1; i < lenA; i++) {
        if (A[i] > A[maxInd]) {
            countMaxVal = 1;
            maxInd = i;
        } else if (A[i] == A[maxInd]) {
            countMaxVal++;
        }
    }
    if(countMaxVal > 1){
        printf("Недопустимый массив A\n");
        return;
    }

    //Находим индексы максимального элемента в матрице B
    int max_row = 0, max_col = 0;
    countMaxVal = 0;
    for (int i = 0; i < lenB; i++) {
        for (int j = 0; j < 9; j++) {
            if (B[i][j] > B[max_row][max_col]){
                max_row = i;
                max_col = j;
            } else if (B[i][j] == B[max_row][max_col]) {
                countMaxVal++;
            }
        }
    }
    if(countMaxVal > 1){
        printf("Недопустимый массив B\n");
        return;
    }
    //Поменять местами элементы
    int temp = A[maxInd];
    A[maxInd] = B[max_row][max_col];
    B[max_row][max_col] = temp;
    printf("Индекс максимального значения A %d\n", maxInd);
    printf("Индекс максимального значения B %d, %d\n", max_row,max_col);
}

void FillTheMas(int *mas, int len){
    for(int i = 0; i < len; i++){
        mas[i] = rand() % 100;
    }
}
void PrintMas(int *mas, int len){
    for(int i = 0; i < len; i +=1){
        printf("%d,\t", mas[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int lenA = 45, lenB = 6, lenBB = 9;
    int A[lenA], B[lenB][lenBB];
    
    //Заполнение
    FillTheMas(A, lenA);
    for(int i = 0; i < lenB; i++){
        FillTheMas(B[i], lenBB);
    }

    //Вывод
    printf("A\n");
    PrintMas(A, lenA);
    printf("B\n");
    for(int i = 0; i < lenB; i++){
        PrintMas(B[i], lenBB);
    }
    

    SwapMaxValues(A, lenA, B, lenB);


    //Вывод
    printf("A\n");
    PrintMas(A, lenA);
    printf("B\n");
    for(int i = 0; i < lenB; i++){
        PrintMas(B[i], lenBB);
    }

    return 0;
}
