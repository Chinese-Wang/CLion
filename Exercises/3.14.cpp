//
// Created by 王京珠 on 2019/9/10.
//

#include <iostream>
#include <cstring>
using namespace std;

int find(char *s,char key){
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if(s[i] == key)
            return i;
    }
    return -1;
}

int is_Variant(char *s,char t[15])
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    int index,flag=0;
    if(len_s != len_t)
        return 0;
    for (int i = 0; i < len_s; ++i) {
        index = find(t,s[i]);
        if(index!=i) flag=1;
        if(index >= 0&&flag==1){
            t[index] = ' ';
        }
    }
    for (int j = 0; j < len_s; ++j) {
        if(t[j] != ' ')
            return 0;
    }
    if(flag == 1) return 1;
    return 0;
}

int main()
{
    char words[15];
    char str[15];
    int flag;
    cout<<"Entry the words:";
    cin>>words;
    cin>>str;
    flag = is_Variant(words,str);
    if(flag)
        cout<<"Yes!"<<endl;
    else
        cout<<"No!"<<endl;
    return 0;
}