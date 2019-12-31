//
// Created by 王京珠 on 2019/11/7.
//

#include <iostream>
using namespace std;


typedef struct {  //辅助数组
    int index1;    //边的顶点1
    int index2;   //边的顶点2
    int weight;   //边的权值
}Element;

const int MAX = 50;
const int MAXINT = 62353;
int arc[MAX][MAX];  //边集合

void Prim(int kinds){  //Prim算法求最小生成树
    int flag[MAX];   //判断顶点是否已被选中
    int arcs = 0;   //最小生成树中边的个数
    Element shortEdge[MAX];
    Element temp;
    flag[0] = true;
    while (arcs != (kinds-1)){
        temp.weight = MAXINT;
        for (int j = 0; j < kinds; ++j) {
            if(flag[j]) {
                for (int k = 0; k < kinds; ++k) {
                    if ((arc[j][k] < temp.weight) && (!flag[k])) {
                        temp.index1 = j;
                        temp.index2 = k;
                        temp.weight = arc[j][k];
                    }
                }
            }
        }
        shortEdge[arcs].index1 = temp.index1;
        shortEdge[arcs].index2 = temp.index2;
        shortEdge[arcs].weight = temp.weight;
        flag[temp.index2] = true;
        arcs++;
    }
    for (int i = 0; i < kinds-1; ++i) {
        cout<<shortEdge[i].index1<<"--->"<<shortEdge[i].index2<<":"<<shortEdge[i].weight<<endl;
    }
}

int main()
{
    int kinds;  //共有多少顶点
    int arcs;   //共有多少条边
    int index1,index2; //边的两条顶点
    int weight;   //边的权值
    cout<<"请输入一共有多少顶点（最多50个顶点）:";
    cin>>kinds;
    for (int i = 0; i < kinds; ++i) {
        for (int j = 0; j < kinds; ++j) {
            arc[i][j] = MAXINT;
        }
    }
    cout<<"请输入共有多少条边:";
    cin>>arcs;
    cout<<"请输入边的两个顶点和权值:";
    for (int i = 0; i < arcs; i++) {
        scanf("%d %d %d",&index1,&index2,&weight);
        arc[index1][index2] = weight;
        arc[index2][index1] = weight;
    }
    Prim(kinds);
    return 0;
}