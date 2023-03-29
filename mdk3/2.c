#include <stdio.h>
int main(){
    int countBart = 0, maxBart = 0, runTime = 0;
    printf("Введите начальное количество бактерий:");
    scanf("%d", &countBart);
    printf("\nВведите значение до которого будут делиться:");
    scanf("%d", &maxBart);
    while (countBart < maxBart) {
        runTime++;
        countBart *= 2;
    }
    printf("\nКоличество пройденного времени- %d", runTime);
    return 0;
}