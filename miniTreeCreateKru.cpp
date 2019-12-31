//
// Created by 王京珠 on 2019/11/10.
//
#include <iostream>
using namespace std;

typedef struct{  //边的结构体
    int index1;  //边的顶点1
    int index2;   //边的顶点2
    int weight;   //边的权值
}Element;

const int MAX = 50;
const int MAXINT = 62353;

void swap(Element &a,Element &b){   //交换两个节点值
    Element tmp;
    tmp.index1 = a.index1;
    tmp.index2 = a.index2;
    tmp.weight = a.weight;
    a.index1 = b.index1;
    a.index2 = b.index2;
    a.weight = b.weight;
    b.index1 = tmp.index1;
    b.index2 = tmp.index2;
    b.weight = tmp.weight;
}

int Partition(Element arc[],int start,int end){
    int i = start;
    int j = end;
    Element tmp;
    while (i<j){
        while (i<j && arc[i].weight<arc[j].weight) j--;  //用边的权值作为排序条件
        if(i<j){
            swap(arc[i],arc[j]);
            i++;
        }
        while (i<j && arc[i].weight<=arc[j].weight) i++;
        if(i<j){
            swap(arc[i],arc[j]);
            j--;
        }
    }
    return i;
}

void QuickSort(Element arc[],int start,int end){ //排序算法
    int mid;
    if(start < end){
        mid = Partition(arc,start,end);
        QuickSort(arc,start,mid-1);
        QuickSort(arc,mid+1,end);
    }
}

/*
 * arc 边集合
 * kinds 共有多少顶点
 * arcs 共有多少条边
 */
void Kruskal(Element *arc,int kinds,int arcs){  //Kruskal算法求最小生成树
    int i;
    int flag[MAX];   //判断顶点是否处于同一连通分量
    int v1,v2;
    for(i=0;i< kinds;i++){  //开始时每个点都处于不同的联通分量中
        flag[i] = kinds+i;
    }
    QuickSort(arc,0,arcs-1);  //对边的集合进行排序
    for(i =0;i<arcs;i++){
        v1 = flag[arc[i].index1];  //获得两个顶点的连通分量
        v2 = flag[arc[i].index2];
        if(v1 != v2) {
            cout << arc[i].index1 << "--->" << arc[i].index2 << ":" << arc[i].weight << endl; //输出最短边
            for (int m = 0; m < kinds; m++) {   //更新联通分量
                if (flag[m] == flag[arc[i].index1] && m != arc[i].index1)
                    flag[m] = i + 1;
                if (flag[m] == flag[arc[i].index2] && m != arc[i].index2)
                    flag[m] = i + 1;
            }
            flag[arc[i].index2] = i+1;
            flag[arc[i].index1] = i+1;
        }
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
    cout<<"请输入共有多少条边:";
    cin>>arcs;
    Element *arc = (Element*)malloc(sizeof(Element)*arcs);
    cout<<"请输入边的两个顶点和权值:";
    for (int i = 0; i < arcs; i++) {
        scanf("%d %d %d",&index1,&index2,&weight);
        arc[i].index1 = index1;
        arc[i].index2 = index2;
        arc[i].weight = weight;
    }
    Kruskal( arc,kinds,arcs);
    free(arc);
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