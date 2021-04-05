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
    int year1, month1, day1;
    int days,row1,row2;
    scanf("%4d%2d%2d",&year, &month, &day);
    scanf("%4d%2d%2d",&year1, &month1, &day1);
    row1 = isLeapYear(year);
    row2 = isLeapYear(year1);
    if (year != year1){
        days = dayTable[row1][month] - day;
        for (int i = month + 1; i < 13; ++i)
            days += dayTable[row1][i];
        for (int i = 1; i < month1; ++i)
            days += dayTable[row2][i];
        days = days + day1 + 1;
    } else{
        if(month != month1){
            days = dayTable[row1][month] - day;
            for (int i = month + 1; i < month1; ++i)
                days += dayTable[row1][i];
            days = days + day1 + 1;
        } else{
            days = day1 - day + 1;
        }
    }
    printf("%d\n",days);
    return 0;
}