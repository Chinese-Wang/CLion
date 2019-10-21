//
// Created by 王京珠 on 2019/9/27.
//

#include <iostream>
#include <cstring>
using namespace std;

int move_len;

void move(char *s,int index,int len){
    if(index == len)
        return;
    int tmp = (index + move_len) % len;
    char c = s[index];
    move(s,index+1,len);
    s[tmp] = c;
}
int main()
{
    char str[80];
    cout<<"输入字符串:";
    cin>>str;
    cout<<"输入位移的距离:";
    cin>>move_len;
    move(str,0,strlen(str));
    cout<<str<<endl;
    return 0;
}