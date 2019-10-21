//
// Created by 王京珠 on 2019/10/5.
//

#include <iostream>
using namespace std;

float MaxValue(int kinds, float *weight, float *price, float needs){
    float *per = new float[kinds];
    float values = 0,max_per = 0;
    int index = 0;
    for (int i = 0; i < kinds; ++i) {
        per[i] = (float)(price[i] / weight[i]);
        if(per[i] > max_per){
            max_per = per[i];
            index = i;
        }
    }
    while (needs != 0){
        if(weight[index] > needs){
            values = per[index] * needs + values;
            break;
        }
        if(weight[index] == needs){
            values = price[index] + values;
            break;
        }
        if(weight[index] < needs){
            values = values + price[index];
            needs = needs - weight[index];
            max_per = 0;
            per[index] = 0;
            for (int i = 0; i < kinds; ++i) {
                if(per[i] > max_per){
                    max_per = per[i];
                    index = i;
                }
            }
        }
    }
    delete[](per);
    return values;
}

int main()
{
    int kinds;
    float needs_weight;
    float weight[100];
    float price[100];
    cin>>kinds>>needs_weight;
    for (int i = 0; i < kinds; ++i) {
        cin>>weight[i];
    }
    for (int i = 0; i < kinds; ++i) {
        cin>>price[i];
    }
    float values = MaxValue(kinds,weight,price,needs_weight);
    printf("%.2f\n",values);
    return 0;
}