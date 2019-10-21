//
// Created by 王京珠 on 2019/9/7.
//

#include <iostream>
#include "stdio.h"
using namespace std;

int f(int a,int b){
    if(b==0) return a;
    f(b,a%b);
}

int main(){
    int num1; //分母
    int num2; //分子
    scanf("%d/%d",&num1,&num2);
    int divisor = f(num1,num2);
    num1 = num1/divisor;
    num2 = num2/divisor;
    printf("%d/%d",num1,num2);
    return 0;
}