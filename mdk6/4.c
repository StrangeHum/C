//Результаты сессии, состоящей из трех экзаменов, для группы из N студентов представлены матрицей К (Nх3). 
//Оценка ставится по четырехбалльной системе; неявка обозначена единицей. 
//Подсчитать количество неявок, неудовлетворительных, удовлетворительных, хороших и отличных оценок по каждому экзамену.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ResultExz(int number);

int n = 4; // количество студентов
int** result; // матрица для хранения результатов экзамена
int veryBad = 0, bad = 0, norm = 0, good = 0, gods = 0; // счетчики оценок

int main(){
    srand(time(NULL));
    
    printf("Введите количество учеников: ");
    scanf("%d", &n);

    for(int i = 1; i <= 3; i++){
        ResultExz(i);
    }
    return 0;
}

void ResultExz(int number){
    result = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++){
        result[i] = malloc(sizeof(int) * 3);
        for(int f = 0; f < 3; f++){
            int t = 1 + (rand() % 4);
            result[i][f] = t;
            printf("%d, ", t);
        }
        printf("\n");
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            if(result[i][j] == 1) { // если студент отсутствует
                veryBad++;
            } else if(result[i][j] == 2) { // если студент получил плохую оценку
                bad++;
            } else if(result[i][j] == 3) { // если учащийся получил удовлетворительную оценку
                norm++;
            } else if(result[i][j] == 4) { // если студент получил хорошую оценку
                good++;
            } else { // если студент получил отличную оценку
                gods++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        free(result[i]);
    free(result);

    // распечатать результаты каждого экзамена
    printf("Результаты экзамена %d:\n", number);
    printf("Неявка: %d\n", veryBad);
    printf("bad: %d\n", bad);
    printf("norm: %d\n", norm);
    printf("good: %d\n", good);
    printf("gods: %d\n", gods);
    
    // сброс счетчиков для следующего экзамена
    veryBad = 0;
    bad = 0;
    norm = 0;
    good = 0;
    gods = 0;
    printf("\n");
}