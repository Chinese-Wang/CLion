//
// Created by Wang on 2021/3/1.
//

#include <stdio.h>

int dayTable[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31},
};

int isLeapYear(int year){
    if (year % 4 == 0 && year % 100 != 0)
        return 1;
    if (year % 400 == 0)
        return 1;
    return 0;
}

int main(){
    int year, month, day;
    int days;
    scanf("%d%d%d%d",&year, &month, &day, &days);
    int leapyear = isLeapYear(year);
    if (days + day >= dayTable[leapyear][month]){
        days = days - dayTable[leapyear][month] + day;
        day = 1;
        month++;
        if (month >= 13){
            month = 1;
            year++;
        }
    } else{
        day = day + days;
        days = 0;
    }
    while (days >= dayTable[leapyear][month]){
        days = days - dayTable[leapyear][month];
        month++;
        if(month >= 13){
            month = 1;
            year++;
        }
    }
    if(days == 0)
        day = 1;
    else
        day = days;
    printf("%04d-%02d-%02d\n",year,month,day);
    return 0;
}