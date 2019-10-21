//
// Created by 王京珠 on 2019/9/7.
//

#include <iostream>
using namespace std;

/*
 * nums 要删除的数组
 * len 数组的长度
 * x 要删除的元素值
 * */
void deletX(int *nums, int &len, int x){
    int index = 0,i = 0;
    int l = len;
    while (index < l){
        if(nums[i] == x){
            index++;
            len--;
        } else{
            i++;
            index++;
        }
        nums[i] = nums[index];
    }
}

int main()
{
    int len ;
    int x;
    cout<<"Input array length:";
    cin>>len;
    int *nums = new int[len];
    cout<<"Enter the value of array:";
    for (int i = 0; i < len; ++i) {
        cin>>nums[i];
    }
    cout<<"Enter the delete value:";
    cin>>x;
    deletX(nums, len, x);
    for (int i = 0; i < len; ++i) {
        cout<<nums[i]<<"  ";
    }
    delete[](nums);
    return 0;
}

