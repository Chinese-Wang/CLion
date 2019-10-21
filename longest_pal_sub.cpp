//
// Created by 王京珠 on 2019/10/21.
//
//最长回文子串
#include <iostream>
#include <cstring>

char* Find1(char *str){//暴力法
    int len = strlen(str);
    int start = 0,end = 0;
    int index,i,j;
    int temp1 = 0, temp2 = 0;
    for (i = 1; i < len/2; ++i) {
        for (j = i-1; j >= 0; --j) {
            index = i+1;
            if(str[j] == str[index]){
                temp1 = j;
                temp2 = index;
            }
            else
                break;
        }
        if(temp2 - temp1 > end - start){
            start = temp1;
            end = temp2;
        }
    }
    for (; i < len-1; ++i) {
        for (j = i-1; j < len; ++j) {
            index = i+1;
            if(str[j] == str[index]){
                temp1 = j;
                temp2 = index;
            }
            else
                break;
        }
        if(temp2 - temp1 > end - start){
            start = temp1;
            end = temp2;
        }
    }
    if(end - start > 0){
        char *res = (char*)malloc(sizeof(char)*(end - start + 1));
        index = 0;
        for (i = start;  i <= end; ++i) {
            res[index] = str[i];
            index++;
        }
        return res;
    }
    else
        return nullptr;
}

int main()
{
    char str[] = "abcba";
    char *res = Find1(str);
    printf("%s\n",res);
    return 0;
}