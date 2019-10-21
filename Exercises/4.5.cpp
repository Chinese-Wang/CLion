//
// Created by 王京珠 on 2019/9/17.
//

#include <iostream>

using namespace std;

int findMax(int *nums,int start,int end){
    if(start == end){
        return nums[start];
    }
    int mid = (start + end) / 2;
    int num1 = findMax(nums,start,mid);
    int num2 = findMax(nums,mid+1,end);
    if(num1 >= num2) return num1;
    else return num2;
}
int main()
{
    int len;
    cout<<"输入数组长度:";
    cin>>len;
    int *nums = new int[len];
    cout<<"输入数组值:";
    for (int i = 0; i < len; ++i) {
        cin>>nums[i];
    }
    int num = findMax(nums,0,len-1);
    printf("%d\n",num);
    return 0;
}