//
// Created by 王京珠 on 2019/9/30.
//
//输入一串乱序字符，将字符按照字母从小到大排列，字符中的数字也按照从大到小的顺序排列在字母后面

#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

void sort(char *s,int len){
    int tmp,compare,i;
    char c;
    int start = 0,end = len-1;
    while (start <= end){
        if(islower(s[start])){
            c = s[start];
            tmp = (int)s[start];
            for (i = start-1; i >= 0; --i) {
                compare = (int)s[i];
                if(compare > tmp){
                    s[i+1] = s[i];
                }
                else
                    break;
            }
            if( i < 0){
                s[0] = c;
            } else
                s[i+1] = c;
            start++;
        }
        else{
            c = s[start];
            s[start] = s[end];
            s[end] = c;
            tmp = (int)s[end];
            for ( i = end+1; i < len; ++i) {
                compare = (int)s[i];
                if(compare < tmp){
                    s[i-1] = s[i];
                } else
                    break;
            }
            if(i == len){
                s[len-1] = c;
            } else{
                s[i-1] = c;
            }
            end--;
        }
    }
}

int main()
{
    char str[80];
    cin>>str;
    int len = strlen(str);
    sort(str,len);
    cout<<str;
    return 0;
}