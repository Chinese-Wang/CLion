//
// Created by Wang on 2021/2/28.
//

#include <stdio.h>

int main(){
    int n;
    int price;
    int flag = 0;
    int x, y ,z;
    while (scanf("%d\n%d %d %d",&n, &x, &y, &z) != EOF){
        flag = 0;
        for (int i = 9; i > 0; --i) {
            for (int j = 9; j >= 0; --j) {
                price = i * 10000 + x * 1000 + y * 100 + z * 10 + j;
                if(price % n == 0){
                    flag = 1;
                    printf("%d %d %d\n",i, j, price / n);
                    break;
                }
            }
            if(flag)
                break;
        }
        if (flag == 0)
            printf("0\n");
    }
    return 0;
}