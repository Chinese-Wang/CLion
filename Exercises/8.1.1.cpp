#include<stdio.h>

#define N 10   //�����10����Ʒ

int weights[N];   //��Ʒ������
int values[N];    //��Ʒ�ļ�ֵ
int capticy;    //��������

void cal_value(int kinds){
    int i = 0;
    int j;
    int w = capticy;
    int select[N];   //����Ƿ������Ʒ������Ϊ1��δ����Ϊ0
    int temp[N];
    int tmp;
    int value = 0;   //��Ʒ�ܼ�ֵ
    for(i = 0;i<kinds;i++){
        select[i] = 0;
    }
    i = 0;
    while(i>=0){
        if(i < kinds) {
            if (weights[i] <= w) {
                select[i] = 1;
                w = w - weights[i];
            } else
                select[i] = 0;
            i++;
        }
        if(i == kinds){
            tmp = 0;
            i = kinds - 1;
            for(j=0;j< kinds;j++){  //����˴α�����Ʒ�ļ�ֵ
                if(select[j])
                    tmp = tmp + values[j];
            }
            if(tmp > value){  //���������Ʒ�ļ�ֵ����֮ǰ����ļ�ֵ
                value = tmp;
                for(j=0;j< kinds;j++)
                    temp[j] = select[j];
            }
            while(i >= 0 && !select[i]){  //����
                i--;
            }
            if(i>=0){  //̽����������
                select[i] = 0;
                w = w + weights[i];
                i++;
            }
        }
    }
    printf("\n�ֱ�����");
    for(i=0;i<kinds;i++){
        if(temp[i]){
            printf("��%d��,",i+1);
        }
    }
    printf("\b��Ʒ\n�ܼ�ֵΪ%d\n",value);
}

int main(){
    int kinds;      //��ѡ����Ʒ������
    int i;
    printf("��������Ʒ�ĸ���(�����ʮ����Ʒ):");
    scanf("%d",&kinds);
    printf("��������Ʒ�������ͼ�ֵ:\n");
    printf("���� ��ֵ\n");
    for(i =0;i< kinds;i++){
        scanf("%d %d",&weights[i],&values[i]);
    }
    printf("�����뱳��������:");
    scanf("%d",&capticy);
    cal_value(kinds);
    return 0;
}
