//
// Created by 王京珠 on 2019/9/10.
//

#include <iostream>
using namespace std;

int main()
{
    float a,b,c,d;
    for (a = 1; a < 711;a++){
        for (b = 1;b < 711; b++){
            for (c = 1;c < 711;c++){
                d = 711 - a - b - c;
                if(a*b*c*d == 711000000){
                    cout<<a/100<<"  "<<b/100<<"  "<<c/100<<"  "<<d/100<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}