//
// Created by 王京珠 on 2019/10/8.
//

#include<iostream>
using namespace std;

int MaxSum1(int *a,int len){ //蛮力法
    int max = 0;
    int tmp;
    for (int i = 0; i < len; ++i) {
        tmp = 0;
        for (int j = i; j < len; ++j) {
            tmp = tmp + a[j];
            if(tmp > max){
                max = tmp;
            }
        }
    }
    return max;
}

int MaxSum2(int *a,int left,int right){ //分治法求最大子段和
    int sum = 0,midSum = 0,leftSum = 0,rightSum = 0;
    int center,s1,s2,lefts,rights;
    if(left == right)
        sum = a[left];
    else{
        center = (left + right) / 2;
        leftSum = MaxSum2(a,left,center);
        rightSum = MaxSum2(a,center + 1,right);
        s1 = 0;
        lefts = 0;
        for (int i = center; i >= left; ++i) {
            lefts = lefts + a[i];
            if (lefts > s1) s1 = lefts;
        }
        s2 = 0;
        rights = 0;
        for (int j = center + 1; j < right; ++j) {
            rights = rights + a[j];
            if (rights > s2) s2 = rights;
        }
        midSum = s1+ s2;
        if(midSum < leftSum) sum = leftSum;
        else sum = midSum;
        if(sum < rightSum) sum = rightSum;
    }
    return sum;
}

int MaxSum3(int *nums,int len){ //动态规划法
    int maxSum = 0,temp = 0;
    for (int i = 0; i < len; ++i) {
        temp = temp + nums[i];
        if(temp < 0){
            temp = 0;
        }
        if(temp > maxSum){
            maxSum = temp;
        }
    }
    return maxSum;
}

int MaxSum4(int *nums, int len){
    int temp = 0,curr = 0,sum = 0;
    for (int i = 0; i < len; ++i) {
        temp = curr + nums[i];
        if(temp > sum)
            sum = temp;
        if(temp > 0)
            curr = temp;
        else
            curr = 0;
    }
    return sum;
}

int main()
{
    int arr[] = {-20,11,-40,70,-5,-2};
    int max = MaxSum4(arr,6);
    cout<<max<<endl;
    return 0;
}