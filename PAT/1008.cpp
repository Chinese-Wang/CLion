//
// Created by ������ on 2019/8/28.
//
#include <iostream>
using namespace std;

void move(int *array,int len,int shift,int deep){
    if(deep == len)
        return;
    int new_locat = (deep + shift) % len;
    int tmp = array[deep];
    move(array,len,shift,deep+1);
    array[new_locat] = tmp;
}

int main()
{
    int len;
    int shift;
    cout<<"��������ĳ��ȣ�";
    cin>>len;
    int *array = new int[len];
    cout<<"��������Ԫ��:";
    for (int i = 0; i < len; ++i) {
        cin>>array[i];
    }
    cout<<"��������λ��:";
    cin>>shift;
    move(array,len,shift,0);
    for (int i = 0; i < len; ++i) {
        printf("%d ",array[i]);
    }
    printf("\b\n");
    return 0;
}