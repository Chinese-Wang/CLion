//
// Created by Wang on 2021/3/24.
//

#include <stdio.h>

//从 1 开始排序，0 位置无元素
void InsertSort(int arr[], int len){
    int i ,j;
    for (i = 2; i < len; i++){
        if (arr[i] < arr[i-1]){
            arr[0] = arr[i];
            arr[i] = arr[i - 1];
            for (j = i-1; arr[0] < arr[j]; --j)
                arr[j + 1] = arr[j];
            arr[j+1] = arr[0];
        }
    }
}

int main(){

}