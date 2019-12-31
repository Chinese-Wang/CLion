//
// Created by 王京珠 on 2019/10/24.
//
#include <iostream>
using namespace std;

const int MAX = 20;  //最大共有20种面值的货币
int money[MAX];  //货币的面值
int need[MAX];   //每种货币各需要多少张
int cost;  //需要花费多少钱

int Exchange(int kind){
    int total = 0;
    for (int i = kind-1; i >= 0; --i) {
        if(cost < money[i]){
            continue;
        }
        if(cost == money[i]){
            need[i] = 1;
            break;
        }
        else{
            need[i] = cost / money[i];
            cost = cost - need[i] * money[i];
        }
    }
    for (int i = 0; i < kind; ++i) {
        total = total + need[i];
    }
    return total;
}

int main()
{
    int kind;
    cout<<"请输入货币的种类:";
    cin>>kind;
    cout<<"请输入每种货币的面值:";
    for (int i = 0; i < kind; ++i)
        cin>>money[i];
    cout<<"请输入要兑换钱数:";
    cin>>cost;
    int total =  Exchange(kind);
    for (int i = 0; i < kind; ++i) {
        if(need[i] != 0 ){
            cout<<"需要"<<money[i]<<"元的"<<need[i]<<"张"<<endl;
        }
    }
    cout<<"\t共需"<<total<<"张货币"<<endl;
    return 0;
}
