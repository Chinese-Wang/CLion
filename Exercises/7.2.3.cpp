//
// Created by ������ on 2019/11/7.
//

#include <iostream>
using namespace std;


typedef struct {  //��������
    int index1;    //�ߵĶ���1
    int index2;   //�ߵĶ���2
    int weight;   //�ߵ�Ȩֵ
}Element;

const int MAX = 50;
const int MAXINT = 62353;
int arc[MAX][MAX];  //�߼���

void Prim(int kinds){  //Prim�㷨����С������
    int flag[MAX];   //�ж϶����Ƿ��ѱ�ѡ��
    int arcs = 0;   //��С�������бߵĸ���
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
    int kinds;  //���ж��ٶ���
    int arcs;   //���ж�������
    int index1,index2; //�ߵ���������
    int weight;   //�ߵ�Ȩֵ
    cout<<"������һ���ж��ٶ��㣨���50�����㣩:";
    cin>>kinds;
    for (int i = 0; i < kinds; ++i) {
        for (int j = 0; j < kinds; ++j) {
            arc[i][j] = MAXINT;
        }
    }
    cout<<"�����빲�ж�������:";
    cin>>arcs;
    cout<<"������ߵ����������Ȩֵ:";
    for (int i = 0; i < arcs; i++) {
        scanf("%d %d %d",&index1,&index2,&weight);
        arc[index1][index2] = weight;
        arc[index2][index1] = weight;
    }
    Prim(kinds);
    return 0;
}