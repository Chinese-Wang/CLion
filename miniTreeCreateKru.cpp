//
// Created by ������ on 2019/11/10.
//
#include <iostream>
using namespace std;

typedef struct{  //�ߵĽṹ��
    int index1;  //�ߵĶ���1
    int index2;   //�ߵĶ���2
    int weight;   //�ߵ�Ȩֵ
}Element;

const int MAX = 50;
const int MAXINT = 62353;

void swap(Element &a,Element &b){   //���������ڵ�ֵ
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
        while (i<j && arc[i].weight<arc[j].weight) j--;  //�ñߵ�Ȩֵ��Ϊ��������
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

void QuickSort(Element arc[],int start,int end){ //�����㷨
    int mid;
    if(start < end){
        mid = Partition(arc,start,end);
        QuickSort(arc,start,mid-1);
        QuickSort(arc,mid+1,end);
    }
}

/*
 * arc �߼���
 * kinds ���ж��ٶ���
 * arcs ���ж�������
 */
void Kruskal(Element *arc,int kinds,int arcs){  //Kruskal�㷨����С������
    int i;
    int flag[MAX];   //�ж϶����Ƿ���ͬһ��ͨ����
    int v1,v2;
    for(i=0;i< kinds;i++){  //��ʼʱÿ���㶼���ڲ�ͬ����ͨ������
        flag[i] = kinds+i;
    }
    QuickSort(arc,0,arcs-1);  //�Աߵļ��Ͻ�������
    for(i =0;i<arcs;i++){
        v1 = flag[arc[i].index1];  //��������������ͨ����
        v2 = flag[arc[i].index2];
        if(v1 != v2) {
            cout << arc[i].index1 << "--->" << arc[i].index2 << ":" << arc[i].weight << endl; //�����̱�
            for (int m = 0; m < kinds; m++) {   //������ͨ����
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
    int kinds;  //���ж��ٶ���
    int arcs;   //���ж�������
    int index1,index2; //�ߵ���������
    int weight;   //�ߵ�Ȩֵ
    cout<<"������һ���ж��ٶ��㣨���50�����㣩:";
    cin>>kinds;
    cout<<"�����빲�ж�������:";
    cin>>arcs;
    Element *arc = (Element*)malloc(sizeof(Element)*arcs);
    cout<<"������ߵ����������Ȩֵ:";
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