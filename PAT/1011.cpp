//
// Created by 王京珠 on 2019/8/29.
//

#include <iostream>
#include <sstream>
using namespace std;

int strlen(char *c){
    int len = 0;
    while (c[len] != '\0'){
        len++;
    }
    return len;
}
void atoi(char c,int num){

}

void add(char *a, char *b,char *res)
{
    int len_a = strlen(a) - 1;
    int len_b = strlen(b) - 1;
    int len_c = len_a>len_b ? len_a :len_b;
    int carry_bit = 0;
    int tmp;
    while ((len_a >=0)&&(len_b>=0)){
         tmp = atoi(a[len_a]) + atoi(b[len_b]) + carry_bit;
         if(tmp > 10){
             carry_bit = 1;
             tmp -= 10;
         } else{
             carry_bit = 0;
         }
         res[len_c] = itoa(tmp);
         len_c--;
         len_a--;
         len_b--;
    }
    while (len_a>=0) {
        if(carry_bit == 0){
            res[len_c] = a[len_a];
        }
        else{
            tmp = atoi(a[len_a]) + carry_bit;
            if(tmp > 10){
                carry_bit = 1;
                tmp = tmp - 10;
            }
            res[len_c] = itoa(tmp);
        }
        len_c--;
        len_a--;
    }
    while (len_b>=0) {
        if(carry_bit == 0){
            res[len_c] = b[len_b];
        }
        else{
            tmp = atoi(b[len_b]) + carry_bit;
            if(tmp > 10){
                carry_bit = 1;
                tmp = tmp - 10;
            }
            res[len_c] = itoa(tmp);
        }
        len_c--;
        len_b--;
    }
}


int main()
{
    char A[12];
    char B[12];
    char res[12];
    //char C[12];
    scanf("%s %s",A,B);
    add(A,B,res);
    printf("%s\n",res);
    return 0;
}