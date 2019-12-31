#include <iostream>
using namespace std;

typedef struct {  
    int adjvex;   //����ڽӱߵĶ���
    int lowcost;   //�ߵ�Ȩֵ
}Element;

const int MAX = 50;
const int MAXINT = 62353;
int arc[MAX][MAX];  //�߼���

void Prim(int kinds){
    int i,j,k;
    int min;
    Element shortEdge[MAX]; //�����50����
    for(i =0;i<kinds;i++){  //��ʼ����̺�ѡ�߼���
        shortEdge[i].lowcost = arc[0][i];
        shortEdge[i].adjvex = 0;  //�Ӷ���0��������̱ߵ��ڽӵ㶼Ϊ0
    }
    shortEdge[0].lowcost = 0;  
    for(i = 0;i<kinds-1;i++){  //ѡ��kinds-1���ߣ�������С������
        min = 100;
        for(j = 0;j< kinds;j++){ //�Ӻ�ѡ��̱߼������ҵ����ʺϵı�
            if((shortEdge[j].lowcost != 0) && (shortEdge[j].lowcost < min)){
                min = shortEdge[j].lowcost;
                k = j;
            }
        }
        cout<<shortEdge[k].adjvex<<"--->"<<k<<endl;  //�������ڽӱߵĶ���
        shortEdge[k].lowcost = 0;  //���ñ���Ϊ��ѡ��״̬
        for(j = 0;j<kinds;j++){    //���º�ѡ��̱߼���
            if(arc[k][j]<shortEdge[j].lowcost){
                shortEdge[j].lowcost = arc[k][j];
                shortEdge[j].adjvex = k;
            }
        }
    }
}

int main()
{
    int kinds;  //���ж��ٶ���
    int arcs;   //���ж�������
    int index1,index2; //�ߵ���������
    int weight;   //�ߵ�Ȩֵ
    int i,j;
    cout<<"������һ���ж��ٶ��㣨���50�����㣩:";
    cin>>kinds;
    for (i = 0; i < kinds; ++i) {
        for (j = 0; j < kinds; ++j) {
            arc[i][j] = MAXINT;
        }
    }
    cout<<"�����빲�ж�������:";
    cin>>arcs;
    cout<<"������ߵ����������Ȩֵ:";
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
