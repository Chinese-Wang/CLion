//
// Created by 王京珠 on 2019/8/28.
//主要解决数组中两个数的最小差问题
//
#include <iostream>
#include <math.h>
using namespace std;

#define MAX_INT 62353;

int main(){
    int array[] = {1,9,7,5,10};
    int difference = MAX_INT;
    for (int i = 0; i < 5; ++i){
        for (int j = i+1; j < 5; ++j){
            if (abs(array[i] - array[j]) < difference)
                difference = abs(array[i] - array[j]);
        }
    }
    cout<<difference<<endl;
    return 0;
}
