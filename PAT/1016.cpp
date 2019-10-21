//
// Created by 王京珠 on 2019/10/4.
//

#include <iostream>
#include <cstring>
using namespace std;

int add_P(char *a,int da,char *b,int db){
    int tmp,pa=0,pb = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int i = 0; i < len_a; ++i) {
        tmp = (int)a[i] - 48;
        if(tmp == da){
            pa = pa * 10 + da;
        }
    }
    for (int i = 0; i < len_b; ++i) {
        tmp = (int)b[i] - 48;
        if(tmp == db){
            pb = pb * 10 + db;
        }
    }
    return pa + pb;
}

int main()
{
    char A[15];
    char B[15];
    int Da,Db;
    scanf("%s %d %s %d",&A,&Da,&B,&Db);
    int P = add_P(A,Da,B,Db);
    cout<<P<<endl;
    return 0;
}