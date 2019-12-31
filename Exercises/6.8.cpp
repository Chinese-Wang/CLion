//
// Created by ������ on 2019/10/24.
//
#include <iostream>
using namespace std;

const int MAX = 20;  //�����20����ֵ�Ļ���
int money[MAX];  //���ҵ���ֵ
int need[MAX];   //ÿ�ֻ��Ҹ���Ҫ������
int cost;  //��Ҫ���Ѷ���Ǯ

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
    cout<<"��������ҵ�����:";
    cin>>kind;
    cout<<"������ÿ�ֻ��ҵ���ֵ:";
    for (int i = 0; i < kind; ++i)
        cin>>money[i];
    cout<<"������Ҫ�һ�Ǯ��:";
    cin>>cost;
    int total =  Exchange(kind);
    for (int i = 0; i < kind; ++i) {
        if(need[i] != 0 ){
            cout<<"��Ҫ"<<money[i]<<"Ԫ��"<<need[i]<<"��"<<endl;
        }
    }
    cout<<"\t����"<<total<<"�Ż���"<<endl;
    return 0;
}
