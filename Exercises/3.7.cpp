//
// Created by 王京珠 on 2019/9/8.
//

#include <iostream>
using namespace std;

int find(int *nums,int start,int end,int key){
    for (int i = start; i < end; ++i) {
        if(nums[i] == key)
            return i+1;
    }
    return 0;
}

void deleteSameValue(int *nums,int &len){
    int flag,end = 1;
    int index = 1;
    int l = len;
    for (int i = 1; i < l;i++) {
        flag = find(nums,0,end,nums[i]);
        if(flag == 0){ //没有重复值
            end++;
        } else{ //有重复值
            len--;
        }
        index++;
        nums[end] = nums[index];
    }
}

int main(){
    int len;
    cout<<"Entry the length of array:";
    cin>>len;
    int *nums = new int[len];
    cout<<"Entry the value of array:";
    for (int i = 0; i < len; ++i) {
        cin>>nums[i];
    }
    deleteSameValue(nums,len);
    for (int i = 0; i < len; ++i) {
        cout<<nums[i]<<"  ";
    }
    return 0;
}