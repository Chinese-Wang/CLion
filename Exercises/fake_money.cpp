//
// Created by 王京珠 on 2019/10/9.
//
//假币问题,假币比真币轻

#include<iostream>
using namespace std;

int judge_fake(int *coins,int start,int end){
    int n1 = start,n2,n3;  //把硬币分为三份，分别是三份的起始下标
    int weight1,weight2,weight3,weight;
    int len = start - end;
    if(len == 1)
        return start + 1;
    if(len == 2){
        if(coins[start] )
    }
    if(len % 3 == 0){
        n2 = n1 + len / 3;
        n3 = n2 + len / 3;
    }
    else{
        n2 = 3;
        n3 = 6;
    }
    weight1 = 0, weight2 = 0, weight3 = 0;
    for (int i = n1; i < n2; ++i)
        weight1 = weight1 + coins[i];
    for(int i = n2; i < n3;i++)
        weight2 = weight2 + coins[i];
    for(int i = n3; i < len;i++)
        weight3 = weight3 + coins[i];
    if(weight1 == weight2){
        return judge_fake(coins,n2,len);
    }
    if(weight1 > weight2){

    }
    /*if(weight1 == weight2){
         if(coins[n1] != coins[n3]) return n3+1;
         else return n3+2;
     }
     if(weight1 > weight2){
         weight1 = weight1 - coins[n1] - coins [n2-1] + coins[n3 -1];
         weight2 = weight2 - coins[n2] - coins[n3-1] + coins[n2-1];
         if(weight1 > weight2){
             if(coins[n3] != coins[n1+1]) return n1+2;
             else return n2+2;
         }
         if(weight1 == weight2){
             if(coins[n3] != coins[n1]) return n1+1;
             else return n2+1;
         }
         if(weight1 < weight2){
             if(coins[n3] != coins[n3-1]) return n3;
             else return n2;
         }
     }
     if(weight1 < weight2){
         weight1 = weight1 - coins[n1] - coins [n2-1] + coins[n3 -1];
         weight2 = weight2 - coins[n2] - coins[n3-1] + coins[n2-1];
         if(weight1 < weight2){
             if(coins[n3] != coins[n1+1]) return n1+2;
             else return n2+2;
         }
         if(weight1 == weight2){
             if(coins[n3] != coins[n1]) return n1+1;
             else return n2+1;
         }
         if(weight1 > weight2){
             if(coins[n3] != coins[n3-1]) return n3;
             else return n2;
         }
     }*/

}

int main()
{
    int coins[] = {2,2,1,2,2,2,2,2,2};
    int index=judge_fake(coins,0,8);
    cout<<index<<endl;
    return 0;
}