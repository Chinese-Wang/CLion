//
// Created by 王京珠 on 2019/9/17.
//

#include <iostream>
using namespace std;

int findMany(const int *nums,int len){
    int many = 0;
    int times = 0,most_time = 0; //number_2是出现最多的次数
    int key = 0;
    for (int i = 0; i < len; ++i) {
        key = nums[i];
        for (int j = i; j < len; ++j) {
            if(nums[j] == key){
                times++;
            }
        }
        if(times > most_time){
            most_time = times;
            many = key;
        }
        times = 0;
    }
    cout<<most_time<<endl;
    return many;
}

int main()
{
    int nums[] = {1,2,3,4,2,2,4,2,3,2};
    int num = findMany(nums,10);
    cout<<num<<endl;
    return 0;
}
