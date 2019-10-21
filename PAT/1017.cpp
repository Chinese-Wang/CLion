//
// Created by 王京珠 on 2019/10/5.
//

#include<iostream>
#include <cstring>
using namespace std;

int char_to_int(char s){
    int num = (int)s - 48;
    return num;
}

void int_to_char(char& s,int num){
    switch(num) {
        case 0: s = '0'; break;
        case 1: s = '1';break;
        case 2: s = '2';break;
        case 3: s = '3';break;
        case 4: s = '4';break;
        case 5: s = '5';break;
        case 6: s = '6';break;
        case 7: s = '7';break;
        case 8: s = '8';break;
        case 9: s = '9';break;
    }

}
/*
 * s 被除数
 * res 商
 * b 除数
 * num 余数
 */
void div(char *s,char *res,int b,int& num){
    int len = strlen(s);
    int tmp = 0; //用作被除数
    int q; //用作商
    num = 0;
    int j = 0;
    for (int i = 0; i < len; ++i) {
        tmp = num*10 + char_to_int(s[i]);
        q = tmp / b; //计算出商
        num = tmp % b;  //计算余数
        if(q == 0 && j == 0)
            continue;
        int_to_char(res[j],q);
        j++;
    }
    res[j] = '\0';
}

int main()
{
    char s[30];
    char res[30]; //商
    int B;
    int reminder; //余数
    cin>>s;
    cin>>B;
    div(s,res,B,reminder);
    cout<<res<<"  "<<reminder<<endl;
    return 0;
}