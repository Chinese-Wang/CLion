//
// Created by ������ on 2019/10/8.
//
//ѭ����ƥ��

#include <iostream>
using namespace std;

void Matching(int **table,int len){
    if(len == 0) {
        return;
    }
    Matching(table,len / 2);
    /*for (int i = len; i < len * 2; ++i) { //�����½�Ԫ��
        for (int j = 0; j < len; ++j) {
            table[i][j] = table[i - len][j] + len;
        }
    }
    for (int i = 0; i < len ; ++i) { //�����Ͻ�Ԫ��
        for (int j = len; j < len * 2 ; ++j) {
            table[i][j] = table[i+len][j - len];
        }
    }
    for (int i = len; i < len * 2; ++i) { //�����½�Ԫ��
        for (int j = len; j < len * 2; ++j) {
            table[i][j] = table[i - len][j - len];
        }
    }*/
    for (int i = 0; i < len; ++i) { //�����Ͻ�
        for (int j = len; j < len * 2; ++j) {
            table[i][j] = table[i][j-len]+len;
        }
    }
    for (int i = len; i < len * 2; ++i) { //�����½�
        for (int j = 0; j < len; ++j) {
            table[i][j] = table[i - len][j] + len;
        }
    }
    for (int i = len; i < len *2; ++i) {
        for (int j = len; j < len*2; ++j) {
            table[i][j] = table[i-len][j-len];
        }
    }
}

int main()
{
    int len;
    cout<<"����ѡ������:";
    cin>>len;
    int **table = (int**)malloc(sizeof(int*)*len);
    for (int i = 0; i < len; ++i)
        table[i] = (int*)malloc(sizeof(int)*len);
    table[0][0]=1;
    Matching(table,len/2);
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            printf("%4d",table[i][j]);
        }
        printf("\n");
    }
    return 0;
}