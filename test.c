//
// Created by Wang Jack on 2020/3/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


/**
 * 寻找nums数组中的众数
 * @param nums
 * @param start
 * @param end
 * @return
 */
int more(const int *nums, int start, int end){
    int num = nums[start];
    int number = 0;
    for(int i = start; i <= end; i++){
        if(num == nums[i])
            number++;
        else{
            number--;
            if(number == 0){
                num = nums[i];
                number = 1;
            }
        }
    }
    return num;
}

int Fab(int level){
    if(level == 0)
        return 0;
    if(level == 1)
        return 1;
    return Fab(level-1) + Fab(level - 2);
}

int isOdd(int num){
    int n = (int)sqrt(num);
    for (int i = 2; i <= n; ++i) {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

void add(int num){
    int n = num / 2;
    int tmp;
    for (int i = 3; i < n; ++i) {
        tmp = num - i;
        if(isOdd(i) && isOdd(tmp))
            printf("%d %d\n",i,tmp);
    }
}

int Pn(int n,int x){
    if(n == 0)
        return 1;
    if (n == 1)
        return x;
    int ans;
    ans = (2*n - 1) * x - Pn(n-1,x) - (n - 1) * Pn(n - 2, x);
    ans = ans / n;
    return ans;
}

int main(){
    printf("\a\n");
    return 0;
}
