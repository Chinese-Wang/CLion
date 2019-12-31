//
// Created by 王京珠 on 2019/10/23.
//

#include <iostream>
using namespace std;

const int MAX = 1000;  //边的权值不能超过1000
int arc[MAX][MAX];   //边权值集合


int CreatGraph(){
    int i,j,k;
    int weight;
    int vnum,arcnum;
    cout<<"请输入顶点的个数和边的个数:";
    cin>>vnum>>arcnum;
    for (i = 0; i < vnum; ++i) {
        for (j = 0; j < vnum; ++j) {
            arc[i][j] = MAX;
        }
    }
    cout<<"请输入边的两个顶点和权值:";
    for (k = 0; k < arcnum; ++k) {
        cin>>i>>j>>weight;
        arc[i][j] = weight;
    }
    /*for (i = 0; i < vnum; ++i) {
        for (j = 0; j < vnum; ++j) {
            cout << arc[i][j] << "\t";
        }
        cout<<endl;
    }*/
    return vnum;  //返回顶点个数
}

void FindPath(int n){
    int *path = (int*)malloc(sizeof(int)*n); //存储路径
    int *cost = (int*)malloc(sizeof(int)*n); //存储从0到每一步的花费
    int i;
    for (int i = 1; i < n; ++i){
        cost[i] = MAX;
        path[i] = -1;
    }
    cost[0] = 0;
    path[0] = -1;
    for (i = 0; i < n; ++i) {
//        printf("i = %d",i);
        for (int j = i+1; j < n; ++j) {
           /* printf("\tj = %d\t",j);
            printf("arc[%d][%d]（%d）+cost[%d]（%d） ?  cost[%d]（%d）\n",i,j,arc[i][j],i,cost[i],j,cost[j]);*/
            if(arc[i][j] + cost[i] < cost[j]){
                cost[j] = arc[i][j] + cost[i];
                path[j] = i;
            }
        }
//        printf("\n\n");
    }
    cout<<"最短路径为:";
    cout<<n-1;
    i = n-1;
    while (path[i] >= 0){
        cout<<"<-"<<path[i];
        i = path[i];
    }
    cout<<endl<<"\t\t长度为:"<<cost[n-1]<<endl;
    free(path);
    free(cost);
}

int main()
{
    int vertex = CreatGraph();  //创建一个图
    FindPath(vertex);
    return 0;
}








