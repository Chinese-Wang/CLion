//
// Created by Wang on 2021/3/1.
//

#include <stdio.h>
#include <string.h>

int main(){
    char ans[28][29] = {' '};
    int n1 = 0,n2 = 0,n;
    char str[81];
    while (scanf("%s",str) != EOF){
        n = strlen(str);
        for (int i = 0; i <= n1; ++i)
            for (int j = 0; j < n2; ++j)
                ans[i][j] = ' ';
        n1 = (n + 2) / 3 - 1;
        n2 = n - 2 * n1;
        for (int i = 0; i < n1; ++i)
            ans[i][0] = str[i];
        for (int i = 0; i < n2; ++i)
            ans[n1][i] = str[i + n1];
        for (int i = 0; i < n1; ++i)
            ans[n1 - i - 1][n2 - 1] = str[n1 + n2 + i];
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                printf("%c",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}