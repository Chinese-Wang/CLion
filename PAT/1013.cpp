//
// Created by 王京珠 on 2019/8/30.
//

#include <iostream>
using namespace std;

int is_prime(int num){
    for (int i = 2; i < num/2; ++i) {
        if(num%i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int start,end;
    cin>>start>>end;
    int i = 0;
    int num = 1;
    int change = 0;
    while (i <= start){
        if(is_prime(num))
            i++;
        num++;
    }
    i--;
    while (i <= end){
        if (is_prime(num)){
            printf("%d ",num);
            i++;
            change++;
        }
        if (change == 10){
            printf("\n");
            change = 0;
        }
        num++;
    }
    return 0;
}