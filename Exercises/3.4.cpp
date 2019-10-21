//
// Created by 王京珠 on 2019/9/8.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    float num1,num2,num3;
    int nums[] = {1,2,3,4,5,6,7,8,9};
    do{
        if((nums[2] != 1) && (nums[6] != 1)){
            num1 = nums[0] * 10 + nums[1];
            num1 *= nums[2];
            num2 = nums[3] * 100 + nums[4] * 10 + nums[5];
            num2 /= nums[6];
            num3 = nums[7] * 10 + nums[8];
            if (num1 + num2 - num3 == 0){
                cout<<nums[0]<<nums[1]<<"*"<<nums[2]<<"+"<<nums[3]<<nums[4]<<nums[5]<<"/"<<nums[6]<<"-"<<nums[7]<<nums[8]<<"=0"<<endl;
            }
        }
    }while (next_permutation(nums,nums+9));
    return 0;
}
