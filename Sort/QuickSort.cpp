//
// Created by 王京珠 on 2019/9/23.
//

#include <iostream>
using namespace std;

int Partition(int nums[],int start,int end){
    int i = start;
    int j = end;
    int tmp;
    while (i<j){
        while (i<j && nums[i]<nums[j]) j--;
        if(i<j){
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
        }
        while (i<j && nums[i] <=nums[j]) i++;
        if(i<j){
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            j--;
        }
    }
    return i;
}

void QuickSort(int nums[],int start,int end){
    int mid;
    if(start < end){
        mid = Partition(nums,start,end);
        QuickSort(nums,start,mid-1);
        QuickSort(nums,mid+1,end);
    }
}

int main(){
    int nums[] = {10,20,15,17,18,14,12,13,16,15};
    QuickSort(nums,0,9);
    for (int num : nums) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}