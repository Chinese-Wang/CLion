//
// Created by 王京珠 on 2019/8/30.
//

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a1[60],a2[60];
    gets(a1);
    gets(a2);
    char flag,flag1;
    int hour;
    int len_1 = strlen(a1);
    int len_2 = strlen(a2);
    int i = 0,j = 0;
    int min;
    while ((i<len_1)&&(j<len_2)){
        if((a1[i] == a2[j]) && ((int)a1[i] > 65)){
            flag = a1[i];
            i++;
            j++;
            break;
        }
        i++;
        j++;
    }
    while ((i<len_1)&&(j<len_2)){
        if((a1[i] == a2[j]) && ((int)a1[i] > 65)){
            flag1 = a1[i];
            break;
        }
        i++;
        j++;
    }
    gets(a1);
    gets(a2);
    len_1 = strlen(a1);
    len_2 = strlen(a2);
    i = 0;
    j = 0;
    while ((i<len_1)&&(j<len_2)){
        if((a1[i] == a2[j]) && ((int)a1[i] >= 65)){
            min = i;
            break;
        }
        i++;
        j++;
    }
    switch (flag){
        case 'A': cout<<"MON ";break;
        case 'B': cout<<"TUE ";break;
        case 'C': cout<<"WED ";break;
        case 'D': cout<<"THU ";break;
        case 'E': cout<<"FRI ";break;
        case 'F': cout<<"SAT ";break;
        case 'G': cout<<"SUN ";break;
    }
    hour = (int)flag1 - 55;
    cout<<hour<<":";
    if(min < 10)
        cout<<"0"<<min<<endl;
    else
        cout<<min<<endl;
    return 0;
}