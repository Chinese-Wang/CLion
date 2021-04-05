//
// Created by ������ on 2019/12/27.
//

#include <iostream>
#include <cstring>
using namespace std;

#define MAXSIZE 100  //�����ַ�����󳤶�

/**
 * ������Ѱ�������������
 * @param str Ҫ����������
 * @param strLen ���鳤��
 * @param ans �������
 */
char* BruteForceLongest(const char *str,int strLen,char ans[]) {
    if (strLen < 2) {  //Ҫ�������ַ�������С��2
        ans[0] = str[0];
        ans[1] = '\0';
        return ans;
    }

    int ansLen = 0;
    char temp[MAXSIZE];   //�ݴ�������

    for (int i = 0; i < strLen; ++i){  //������ĸΪ���Ĵ���ʼ�ַ�
        for (int j = strLen - 1; j > i; --j) {   //�ҵ�������ĸ���Ӧ���ַ�
            if (str[i] == str[j]) {  //���ַ�ȷʵ�ǻ��ĵ���ɲ���
                int tempLen = 2;        //�����ַ�������Ϊ2�������Ļ����ַ�
                int num = 0;    //��ƥ����Ļ����ַ�����
                temp[num++] = str[i];  //����ƥ��Ļ����ַ���������temp��
                int index1;    //index1ָ����Ŀ�ʼ��
                int index2;    //index2ָ����Ĵ���ĩβ
                for (int l = 0; l < j - i; ++l) {  //ѭ��j-i�Σ���ÿһ���ַ�������ɵĻ��Ķ�Ѱ��һ��
                    int tempLen1 = tempLen;   //��ʱ�������ݴ�tempLen��ֵ
                    int tempIndex1 = i + l + 1;  //��ʱ��������ʾÿ�ο�ʼѰ�һ�������ʱ���±�
                    int tempIndex2 = j-1;  //�����ϴλ���������ƥ��Ľ����±�
                    int tempNum = num;  //��ʱ�������ݴ���ƥ��Ļ����ַ�����
                    index1 = tempIndex1;  //�Ӵ�ƥ�俪ʼ��
                    index2 = tempIndex2; //�Ӵ�ƥ�������
                    while (index1 <= index2) {     //������β��Ӧ�еĻ��Ĵ�
                        if (index1 == index2) {   //���Ҫ���һ��Ĵ�ֻʣһ���ַ�
                            temp[tempNum++] = str[index1];  //���������ʶ��������
                            tempLen1 += 1; //���鳤�ȼ�һ
                            break;
                        }
                        while (str[index1] != str[index2] && index2 > index1) index2--;  //��β����ʼ���뿪ʼ����ͬ��Ԫ��
                        if (str[index1] == str[index2] && index1 != index2) {   //�ҵ�ֵ��ͬ���±겻ͬ��Ԫ��
                            temp[tempNum++] = str[index1];    //��Ԫ�طŵ�������
                            tempLen1 += 2;    //���ȼӶ�
                            index2--;  //β����ǰ�ƶ�
                            tempIndex2 = index2;
                        } else
                            index2 = tempIndex2;  //û���ҵ������ַ���ͬ��Ԫ�أ�β���ƶ�����ʶ��β��λ��
                        index1++;  //�ײ���ǰ�ƶ�
                    }
                    if (tempLen1 > ansLen) {   //������ҵ��Ļ������г��ȴ���֮ǰ�ĳ���
                        ansLen = tempLen1;
                        for (int copyIndex = 0; copyIndex < tempNum; ++copyIndex) { //��Ԫ�ظ��Ƶ��������
                            ans[copyIndex] = temp[copyIndex];
                            ans[tempLen1 - copyIndex - 1] = temp[copyIndex];
                        }
                        ans[ansLen] = '\0';
                    }
                }
            }
        }
    }
    if(ansLen == 0){
        ans[0] = str[0];
        ans[1] = '\0';
    }
    return ans;
}

/**
 * ��̬�滮����������������
 * @param str Ҫ�������ַ���
 * @param strLen �ַ�������
 * @param ans �������
 */
void DynProLongest(const char *str,int strLen,char ans[]){
    int ansLen = 0;   //���鳤��

    if(strLen < 2) {   //���ԭ�ַ�����С��2
        ans[0] = str[0];
        ans[1] = '\0';
        return;
    }
    //�������飬Ԫ�س�ֵȫΪ0��dp[i][j]��ʾ��i��j���ַ����е�����������еĳ���
    int dp[MAXSIZE][MAXSIZE];
    //״̬���飬ָ��Ԫ�ػ��ݵķ���1 ��Խ��߷�����ݣ�i+1,j-1��,2 ��ǰ���ݣ�i��j-1����3 ���»��ݣ�i+1��j��
    int status[MAXSIZE][MAXSIZE];

    for (int i = strLen-1; i >=0 ; --i){  //�Ӻ���ǰ��������
        dp[i][i] = 1;    //����Ԫ�ؿ����ǻ���
        status[i][i] = 1;  //�Խ��߻���
        for (int j = i+1; j < strLen ; ++j){
            if(str[i] == str[j]){   //�ҵ�������ͬ�ַ�
                dp[i][j] = dp[i+1][j-1] + 2;
                status[i][j] = 1;    //��Խ��߻���
            }else {   //����Ԫ��ֵ����
                if (dp[i + 1][j] > dp[i][j - 1]){  //�ҵ��������е���󳤶�
                    dp[i][j] = dp[i + 1][j];
                    status[i][j] = 3;    //���»���
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    status[i][j] = 2;   //��ǰ����
                }
            }
        }
    }
    int i = 0,j = strLen-1;
    while(i <= j){  //���ݸ�ֵ
        if(status[i][j] == 1){   //����1��������ַ��ǻ������е���ɲ���
            ans[ansLen++] = str[i];
            i++;
            j--;
        }
        if(status[i][j] == 2) j--;   //��ǰ����
        if(status[i][j] == 3) i++;   //���»���
    }
    int index = dp[0][strLen-1] - ansLen-1;
    for(i = 0;i < index + 1;i++){  //���������е���һ�븴��
        ans[ansLen++] = ans[index - i];
    }
    ans[ansLen] = '\0';
}

/**
 * ���ļ��������ļ�ָ��
 * @return FILE*
 */
FILE* fileOpen()
{
    char fileName[20];   //���������ļ���
    FILE *fp;    //�ļ�ָ��

    printf("�������ȡ�ļ���:");
    scanf("%s", fileName);

    fp=fopen(fileName, "r");  //���ļ�
    return fp;   //�����ļ�ָ��
}

/**
 * ��ȡһ������
 * @param fp �ļ�ָ��
 * @param str ���������ַ���
 * @return char
 */
char readLine(FILE* fp,char* str){
    char ch = (char)fgetc(fp);  //�ȶ�ȡһ��Ԫ��,fgetc()����ֵΪint�����ض����ַ���ASCII��
    int i = 0;
    while(ch != EOF && ch != '\n'){   //�ļ���ĩβ���˻��з�
        str[i] = ch;
        ch = (char)fgetc(fp);
        i++;
    }
    str[i] = '\0';
    return ch;
}

int main()
{
    char str[MAXSIZE];  //����Ҫ�������ַ���
    char bfl[MAXSIZE];  //�����������Ľ��
    char dpl[MAXSIZE];  //��̬�滮�������Ľ��
    char ch = ' ';  //�˳���ȡ�ļ��ı�־

    FILE *fp = fileOpen();   //���ļ�
    if(fp == nullptr){      //���ļ�ʧ��
        printf("����,�ļ��򲻿�,�����ļ���\n");
    }
    else{
        printf(" %s    \t %s\t%s\n","ԭ�ַ���","���������","��̬�滮���");
        while(ch != EOF){   //�ļ�û�ж���ĩβ
            ch = readLine(fp,str);   //ÿ�ζ�ȡһ�У������ݶ���str�ַ�������
            int strLen =strlen(str);   //��ȡ�ַ�������
            BruteForceLongest(str,strLen,bfl);  //�����������������������
            DynProLongest(str,strLen,dpl);
            printf("%-15s",str);    //���Ŀ���ַ���
            printf("%-15s",bfl);   //����ҵ�������Ĵ�
            printf("%-15s\n",dpl);   //����ҵ�������Ĵ�
        }
        fclose(fp);
    }
    return 0;
}

// E:/C++/test.txt