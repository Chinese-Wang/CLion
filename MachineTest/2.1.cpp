//
// Created by Wang on 2021/2/28.
//

#include <stdio.h>

// 0 相关 1 无关
int isRelevant(int num){
    int tmp;
    if(num % 7 == 0)
        return 0;
    while (num != 0){
        tmp = num % 10;
        if(tmp == 7)
            return 0;
        num /= 10;
    }
    return 1;
}

int main(){
    int n;
    int ans = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        if(isRelevant(i))
            ans += i * i;
    }
    printf("%d\n",ans);
    return 0;
}
