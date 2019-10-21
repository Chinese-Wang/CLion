//
// Created by 王京珠 on 2019/8/28.
//

#include <iostream>
using namespace std;

int main()
{
    char sentence[80];
    gets(sentence);
    int len = _mbstrlen(sentence);
    char *res = new char[len+1];
    int start = 0; //res复制起始点
    int index,end;
    for (int i = len-1; i > 0 ; --i) {
        end = i;
        while ((sentence[i]!=' ')&&(i > -1)){
            i--;
        }
        index = i + 1;
        for (; index <= end; ++index,start++) {
            res[start] = sentence[index];
        }
        res[start++] = ' ';
    }
    res[len] = '\0';
    printf(res);
    delete[](res);
    return 0;
}