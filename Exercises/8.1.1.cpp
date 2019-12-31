#include<stdio.h>

#define N 10   //最多有10种物品

int weights[N];   //物品的重量
int values[N];    //物品的价值
int capticy;    //背包容量

void cal_value(int kinds){
    int i = 0;
    int j;
    int w = capticy;
    int select[N];   //标记是否放入物品，放入为1，未放入为0
    int temp[N];
    int tmp;
    int value = 0;   //物品总价值
    for(i = 0;i<kinds;i++){
        select[i] = 0;
    }
    i = 0;
    while(i>=0){
        if(i < kinds) {
            if (weights[i] <= w) {
                select[i] = 1;
                w = w - weights[i];
            } else
                select[i] = 0;
            i++;
        }
        if(i == kinds){
            tmp = 0;
            i = kinds - 1;
            for(j=0;j< kinds;j++){  //计算此次背包物品的价值
                if(select[j])
                    tmp = tmp + values[j];
            }
            if(tmp > value){  //如果背包物品的价值大于之前计算的价值
                value = tmp;
                for(j=0;j< kinds;j++)
                    temp[j] = select[j];
            }
            while(i >= 0 && !select[i]){  //回溯
                i--;
            }
            if(i>=0){  //探索其他子树
                select[i] = 0;
                w = w + weights[i];
                i++;
            }
        }
    }
    printf("\n分别拿了");
    for(i=0;i<kinds;i++){
        if(temp[i]){
            printf("第%d件,",i+1);
        }
    }
    printf("\b物品\n总价值为%d\n",value);
}

int main(){
    int kinds;      //能选择物品的种类
    int i;
    printf("请输入物品的个数(最多有十个物品):");
    scanf("%d",&kinds);
    printf("请输入物品的重量和价值:\n");
    printf("重量 价值\n");
    for(i =0;i< kinds;i++){
        scanf("%d %d",&weights[i],&values[i]);
    }
    printf("请输入背包的容量:");
    scanf("%d",&capticy);
    cal_value(kinds);
    return 0;
}
