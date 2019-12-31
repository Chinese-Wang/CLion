//
// Created by 王京珠 on 2019/9/7.
//

#include <iostream>
#include <cstring>
using namespace std;

void GetNext(char* T,int *next){
    int j = 0,k = -1;
    next[0] = -1;
    while (T[j] != '\0'){
        if(k == -1){
            next[++j] = 0;
            k = 0;
        } else if(T[j] == T[k]){
            k++;
            next[++j] = k;
        } else{
            k = next[k];
        }
    }
}

int KMP(char* S,char *T){
    int j = 0,i = 0;
    int next[80];
    GetNext(T,next);
    while (S[i] != '\0' && T[j] != '\0'){
        if(S[i]==T[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
            if(j == -1){
                i++;
                j++;
            }
        }
    }
    if(T[j] == '\0') return (i-strlen(T)+1);
    else return 0;
}

int main(){
    char S[80];
    /*char T[80];
    cin>>S>>T;
    int index = KMP(S,T);*/
    cin>>S;
    int len = strlen(S);
    int next[100];
    GetNext(S,next);
    for (int i = 0; i < len; ++i)
        cout<<next[i]<<"\t";
    return 0;
}