#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void) {
    //Переменные 
    int a=1; 
    float b=2; 
    double c=3; 
    //Указатели 
    int *p1=&a; 
    float *p2=&b; 
    double *p3=&c; 
    void *p4; 
    // Адреса переменных и размер выделяемой памяти 
    printf("a: int: start address %p \\ extent %d\n", &a, sizeof(a));           //адрес, кол-во занимаемое байтов типом int
    printf("b: float: start address %p \\ extent %d\n", &b, sizeof(b));         //адрес, кол-во занимаемое байтов типом float
    printf("c: double: start address %p \\ extent %d\n\n", &c, sizeof(c));      //адрес, кол-во занимаемое байтов типом double
    //Адреса указателей и размер выделяемой памяти 
    printf("p1: pointer: start address %p \\ extent %d\n", &p1, sizeof(p1));    //адрес, кол-во занимаемое байтов типом int*
    printf("p2: pointer: start address %p \\ extent %d\n", &p2, sizeof(p2));    //адрес, кол-во занимаемое байтов типом float*
    printf("p3: pointer: start address %p \\ extent %d\n\n", &p3, sizeof(p3));  //адрес, кол-во занимаемое байтов типом double*
    //Значения, на которые ссылаются указатели 
    printf("p1: %p related value %d\n",p1,*p1);                                 //адрес, значение лежащее за указателем "p1"
    printf("p2: %p related value %f\n",p2,*p2);                                 //адрес, значение лежащее за указателем "p2"
    printf("p3: %p related value %lf\n\n",p3,*p3);                              //адрес, значение лежащее за указателем "p3"
    //Использование указателей в выражениях 
    printf("a=%d\tb=%f\tc=%lf\n", a, b, c);                                     //значения лежащеие в полях "a", "b", "c"
    *p1=5;                                                                      //значение лежащее за указателем "p1" изменяется на 5
    *p2=*p2*(*p1);                                                              //значение лежащее за указателем "p2" изменяется на *p2*(*p1) -> b * a -> 1*5
    *p3=sqrt(*p3);                                                              //значение лежащее за указателем "p3" возводим в кв. корень
    printf("a=%d\tb=%f\tc=%lf\n",a,b,c);
    printf("*p1=%d\t*p2=%f\t*p3=%lf\n\n", *p1, *p2, *p3);
    //Присваивание указателей p1=(int*)p2; 
    p3=(double*)p2;                                                             //При помощи явного преобразования указатель "p3" теперь ссылается на указатель "p2"
    p4=p2;                                                                      //указатель "p4" ссылается на "p2"
    printf("p1=%p\tp2=%p\tp3=%p\tp4=%p\n", p1, p2, p3, p4);
    printf("*p1=%d\t*p2=%f\t*p3=%lf\t*(float*)p4=\\ %f\n\n", *p1, *p2, *p3, *(float*)p4); //тк компилятор не умеет работать с типом void*, поэтому необходимо изпользовать явное преобразование к типу, в данном случае к типу указателя float*
    //Изменение значений указателей 
    p1++;   //указатель "p1" сдвигается на +1
    p3--;   //указатель "p1" сдвигается на -1
    printf("p1=%p\tp2=%p\tp3=%p\n", p1, p2, p3); 
    printf("*p1=%d\t\t*p2=%f\t*p3=%lf\n", *p1, *p2, *p3); 
    p1-=4;  //указатель "p1" сдвигается на -4
    p3=(double*)&a-1; //указатель "p1" сдвигается в ячейку (double*)&a-1 и при помощи явного преобразования получаем адрес ячейки "a", сдвинутую на -1
    printf("p1=%p\tp2=%p\tp3=%p\n",p1,p2,p3); 
    printf("*p1=%d\t*p2=%f\t*p3=%lf\n", *p1, *p2, *p3); 
    system("pause");
    return 0;
}