//
// Created by Wang on 2021/2/28.
//

#include <stdio.h>

int main(){
    int n;
    int z = 0;
    float sum;
    scanf("%d",&n);
    for(int x = 0; x <= 100; ++x){
        for(int y = 0; y <= 100; y++){
            z = 100 - x - y;
            if (z < 0)
                break;
            sum = 5 * x + 3 * y + 0.33 * z;
            if(sum < n)
                printf("x = %d, y = %d, z = %d\n",x,y,z);
        }
    }
}
