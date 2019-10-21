//
// Created by 王京珠 on 2019/10/8.
//
//循环赛匹配

#include <iostream>
using namespace std;

void Matching(int **table,int len){
    if(len == 0) {
        return;
    }
    Matching(table,len / 2);
    /*for (int i = len; i < len * 2; ++i) { //填左下角元素
        for (int j = 0; j < len; ++j) {
            table[i][j] = table[i - len][j] + len;
        }
    }
    for (int i = 0; i < len ; ++i) { //填右上角元素
        for (int j = len; j < len * 2 ; ++j) {
            table[i][j] = table[i+len][j - len];
        }
    }
    for (int i = len; i < len * 2; ++i) { //填右下角元素
        for (int j = len; j < len * 2; ++j) {
            table[i][j] = table[i - len][j - len];
        }
    }*/
    for (int i = 0; i < len; ++i) { //填右上角
        for (int j = len; j < len * 2; ++j) {
            table[i][j] = table[i][j-len]+len;
        }
    }
    for (int i = len; i < len * 2; ++i) { //填左下角
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
    cout<<"输入选手人数:";
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