//
// Created by 王京珠 on 2019/9/6.
//

#include <iostream>
#include <cstring>
using namespace std;

int BF(char *S,char *T){
    int index = 0;
    int j=0,i = 0;
    while (S[i] != '\0'&&T[j]!='\0'){
        if(S[i] == T[j]){
            i++;
            j++;
        }
        else{
            index++;
            i = index;
            j=0;
        }
    }
    if(T[j]=='\0') return index+1;
    else return 0;
}

/*
 * S 被替换的字符串
 * start 替换起始位置
 * len_replace 要替换字符串的长度
 * add 要替换的字符串*/
void replace(char *S,int start,int len_replace,char *add){
    int len_S = strlen(S);  //S的长度
    int len_add = strlen(add); //要更换字符串长度
    int index,time;
    int different = len_replace - len_add;
    time = len_S - start - len_replace;
    if(different > 0){
        index = start + len_add;
        for (int i = 0; i <= time; ++i) {
            S[index] = S[index + different];
            index++;
        }
    }
    if(different < 0){
        index = len_S + len_add - len_replace;
        for (int i = 0; i <= time; ++i) {
            S[index] = S[index + different];
            index--;
        }
    }
    for (int i = 0; i < len_add; ++i) {
        S[start] = add[i];
        start++;
    }
}

int main()
{
    char S[20];
    char T[10];
    char add[20];
    cin>>S>>T;
    int index = BF(S,T);
    while (index != 0){
        cout<<"Enter the characters to replace:";
        cin>>add;
        replace(S,index-1,strlen(T), add);
        index = BF(S,T);
    }
    cout<<S<<endl;
    return 0;
}