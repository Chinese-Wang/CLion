//
// Created by 王京珠 on 2019/8/28.
//一元多项式求导

#include <iostream>
using namespace std;

int main()
{
    int ratio;//系数
    int index; //指数
    char flag;
    scanf("%d %d%c",&ratio,&index,&flag);
    while (flag != '\n'){
        if(index == 0 || ratio == 0){
            cin>>ratio>>index>>flag;
            continue;
        }
        ratio = ratio * index;
        index -= 1;
        cout<<ratio<<" "<<index<<" ";
        scanf("%d %d%c",&ratio,&index,&flag);
    }
    return 0;
}