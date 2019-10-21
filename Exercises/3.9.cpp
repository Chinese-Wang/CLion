//
// Created by 王京珠 on 2019/9/8.
//

#include <iostream>
#include <cstring>
using namespace std;

void reorganize(char *str){
    int len = strlen(str);
    int len_R = 0,len_W = 0,len_B = 0;
    for (int i = 0; i < len; ++i) {
        if(str[i] == 'R'){
            len_R++;
        } else if(str[i] == 'W'){
            len_W++;
        } else{
            len_B++;
        }
    }
    for (int i = 0; i < len_R; ++i) {
        str[i] = 'R';
    }
    for (int i = len_R; i < len_R+len_W; ++i) {
        str[i] = 'W';
    }
    for (int i = len_R+len_W; i < len; ++i) {
        str[i] = 'B';
    }
}

int main()
{
    char str[80];
    cout<<"Entry the string:";
    cin>>str;
    reorganize(str);
    cout<<str<<endl;
    return 0;
}