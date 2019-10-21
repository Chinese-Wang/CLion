//
// Created by 王京珠 on 2019/10/5.
//

#include <iostream>
using namespace std;

void win_census(char *record_x,char *record_y,int *census_x,int *census_y,char *win,int len){
    int x_c = 0,x_j = 0,x_b = 0;
    int y_c = 0,y_j = 0,y_b = 0;
    for (int i = 0; i < len; ++i) {
        if(record_x[i] == record_y[i]){
            census_x[1]++;
            census_y[1]++;
            continue;
        }
        if(record_x[i] == 'C'){
            if(record_y[i] == 'B'){
                census_x[2]++;
                census_y[0]++;
                y_b++;
                continue;
            }
            if(record_y[i] == 'J'){
                census_x[0]++;
                census_y[2]++;
                x_c++;
                continue;
            }
        }
        if(record_x[i] == 'J'){
            if(record_y[i] == 'C'){
                census_x[2]++;
                census_y[0]++;
                y_c++;
                continue;
            }
            if(record_y[i] == 'B'){
                census_x[0]++;
                census_y[2]++;
                x_j++;
                continue;
            }
        }
        if(record_x[i] == 'B'){
            if(record_y[i] == 'J'){
                census_x[2]++;
                census_y[0]++;
                y_j++;
                continue;
            }
            if(record_y[i] == 'C'){
                census_x[0]++;
                census_y[2]++;
                x_b++;
                continue;
            }
        }
    }
    if(x_c > x_b){
        if(x_c >= x_j)
            win[0] = 'C';
        else
            win[0] = 'J';
    } else{
        if(x_b >= x_j) win[0] = 'B';
        else win[0] = 'J';
    }
    if(y_c > y_b){
        if(y_c >= y_j) win[1] = 'C';
        else win[1] = 'J';
    } else{
        if(y_b >= y_j) win[1] = 'B';
        else win[1] = 'J';
    }
}

int main()
{
    char x[50];
    char y[50];
    int x_i[3] = {0,0,0};
    int y_i[3] = {0,0,0};
    char x_win,y_win;
    char win[2];
    int len;
    cin>>len;
    getchar();
    for (int i = 0; i < len; ++i) {
        scanf("%c %c",&x[i],&y[i]);
        getchar();
    }
    win_census(x,y,x_i,y_i,win,len);
    printf("%d %d %d\n",x_i[0],x_i[1],x_i[2]);
    printf("%d %d %d\n",y_i[0],y_i[1],y_i[2]);
    printf("%c %c\n",win[0],win[1]);
    return 0;
}