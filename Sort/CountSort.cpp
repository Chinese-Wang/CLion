//
// Created by Wang on 2021/3/23.
//

#include "stdio.h"

const int MAXN = 100;


int main(){
    int n;
    int arr[MAXN] = {0};
    int num[MAXN] = {0};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
        num[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i < MAXN; ++i) {
        while (num[i] != 0){
            arr[index] = i;
            index++;
            num[i] --;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}