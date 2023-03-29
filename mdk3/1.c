#include <stdio.h>

int main() {
    int counter = 0;
    for (int i = 0; i < 1000; i++){
        if (i % 25 == 0 && i % 3 != 0){
            counter++;
        }
    }
    printf("Количество натуральных чисел меньше 1001,но кратных 25 и не кратных 3 - %d\n", counter);
    return 0;
}