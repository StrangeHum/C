#include <stdio.h>

void PrintDate();

int day, month, years;
char week[7][10]={
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thuesday",
    "Friday",
    "Saturday"
};

int main()
{
    printf("\nEnter date in format (dd mm yyyy): ");
    scanf("%d%d%d",&day,&month,&years);
    if (
        ((1 > day ) || (day > 31))
        || 
        ((1 > month) || (month > 12))
        || 
        (1800 > years)
        ){
        printf("Invalid date format entered");
        return 0;
    }
    else if(month == 2 && day > 29)
    {
        printf("Invalid date format entered");
        return 0;
    }
    PrintDate();
}

void PrintDate()
{
    int a, y, m, R;
    a = ( 14 - month ) / 12;
    y = years - a;
    m = month + 12 * a - 2;
    R = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12 );
    printf("%s",week[R % 7]);
}
