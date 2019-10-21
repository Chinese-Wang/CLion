//
// Created by 王京珠 on 2019/10/5.
//

#include <iostream>
using namespace std;

void inc_sort(int *nums){ //递增排序
    int tmp;
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            if(nums[i] > nums[j]){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

void non_inc_sort(int *nums){ //非递增排序
    int tmp;
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            if(nums[i] < nums[j]){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

void separate(int num,int* arr){
    int i = 0;
    while (num != 0){
        arr[i] = num % 10;
        num = num / 10;
        i++;
    }
}

int main()
{
    int num,res = 1;
    int inc,non_inc;
    cin>>num;
    int arr[4];
//    separate(num,arr);
    while (num != 6174 && num != 0){
        separate(num,arr);
        inc_sort(arr);
        inc = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
        non_inc_sort(arr);
        non_inc = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
        num = non_inc - inc;
        printf("%04d-%04d=%d\n",non_inc,inc,num);
    }
    /*inc_sort(arr);
    cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<endl;
    non_inc_sort(arr);
    cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<endl;*/
    return 0;
}