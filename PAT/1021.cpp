//
// Created by 王京珠 on 2019/10/6.
//

#include<iostream>
#include <cstring>
using namespace std;

void sort(int *nums,int len){ //递增排序
    int tmp;
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            if(nums[i] > nums[j]){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

int main(){
    int arr[10];
    int tmp,count;
    char str[11];
    cin>>str;
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        arr[i] = (int)str[i] - 48;
    }
    sort(arr,len);
    for (int i = 0; i < len;){
        tmp = arr[i];
        count = 0;
        while ((tmp == arr[i]) && (i < len)) {i++; count++;}
        printf("%d:%d\n",tmp,count);
    }
    return 0;
}