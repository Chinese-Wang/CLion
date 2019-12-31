#include <iostream>
using namespace std;

typedef struct {  
    int adjvex;   //最短邻接边的顶点
    int lowcost;   //边的权值
}Element;

const int MAX = 50;
const int MAXINT = 62353;
int arc[MAX][MAX];  //边集合

void Prim(int kinds){
    int i,j,k;
    int min;
    Element shortEdge[MAX]; //最多有50条边
    for(i =0;i<kinds;i++){  //初始化最短侯选边集合
        shortEdge[i].lowcost = arc[0][i];
        shortEdge[i].adjvex = 0;  //从顶点0出发，最短边的邻接点都为0
    }
    shortEdge[0].lowcost = 0;  
    for(i = 0;i<kinds-1;i++){  //选出kinds-1条边，构成最小生成树
        min = 100;
        for(j = 0;j< kinds;j++){ //从候选最短边集合中找到最适合的边
            if((shortEdge[j].lowcost != 0) && (shortEdge[j].lowcost < min)){
                min = shortEdge[j].lowcost;
                k = j;
            }
        }
        cout<<shortEdge[k].adjvex<<"--->"<<k<<endl;  //输出最短邻接边的顶点
        shortEdge[k].lowcost = 0;  //将该边置为已选中状态
        for(j = 0;j<kinds;j++){    //更新候选最短边集合
            if(arc[k][j]<shortEdge[j].lowcost){
                shortEdge[j].lowcost = arc[k][j];
                shortEdge[j].adjvex = k;
            }
        }
    }
}

int main()
{
    int kinds;  //共有多少顶点
    int arcs;   //共有多少条边
    int index1,index2; //边的两条顶点
    int weight;   //边的权值
    int i,j;
    cout<<"请输入一共有多少顶点（最多50个顶点）:";
    cin>>kinds;
    for (i = 0; i < kinds; ++i) {
        for (j = 0; j < kinds; ++j) {
            arc[i][j] = MAXINT;
        }
    }
    cout<<"请输入共有多少条边:";
    cin>>arcs;
    cout<<"请输入边的两个顶点和权值:";
    for (i = 0; i < arcs; i++) {
        scanf("%d %d %d",&index1,&index2,&weight);
        arc[index1][index2] = weight;
        arc[index2][index1] = weight;
    }
    Prim(kinds);
    return 0;
}



/*
0 1 34
0 2 46
0 5 19
1 4 12
2 5 25
2 3 17
3 5 25
3 4 38
4 5 26
*/
