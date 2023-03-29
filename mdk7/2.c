//Определить, состоят ли целочисленные массивы А (16) и В (18) из одинаковых наборов значений. 
//Элементы в массивах могут располагаться в произвольном порядке, одно и то же значение может встречаться неоднократно.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define lenA 16
#define lenB 18

int A[lenA], B[lenB];

void FillTheMas(int *mas, int len){
    for(int i = 0; i < len; i++){
        mas[i] = rand() % 10;
    }
}

void PrintMas(int *mas, int len){
    for(int i = 0; i < len; i +=1){
        printf("%d,\t", mas[i]);
    }
    printf("\n");
}

int Check(int value){
    for (int i = 0; i < lenA; i++){
        if(value == B[i]){
            return -1;
        }
    }
    return -2;
}


int main()
{
    srand(time(NULL));
    
    FillTheMas(A, lenA);
    FillTheMas(B, lenB);
    
    PrintMas(A, lenA);
    PrintMas(B, lenB);
    
    for (int i = 0; i < lenA; i++){
        if(Check(A[i]) == -2){
            printf("целочисленные массивы А (16) и В (18) не состоят из одинаковых наборов значений");
            return 0;
        }
    }
    printf("целочисленные массивы А (16) и В (18) состоят из одинаковых наборов значений");
    return 0;
}
