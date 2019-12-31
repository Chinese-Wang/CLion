//
// Created by ������ on 2019/12/27.
//

//Ѱ�������������

#include <iostream>
#include <cstring>
using namespace std;

#define MAXSIZE 100  //�����ַ�����󳤶�

/**
 * ��������������������
 * str Ŀ���ַ���
 * strLen Ŀ���ַ�������
 * ����ֵ �ҵ��������������
 * @return  char*
 */
char* BruteForceLongest(const char *str,int strLen) {
    char *ans = new char[strLen];  //�������
    int ansLen = 0;   //���鳤��

    if(strLen < 2) {
        ans[0] = str[0];
        ans[1] = '\0';
        return ans;
    }

    char *temp = new char[strLen];

    for (int i = 0; i < strLen; ++i) {  //������ĸΪ���Ĵ���ʼ�ַ�
        for (int j = strLen - 1; j > i; --j) {   //�ҵ�������ĸ���Ӧ���ַ�
            int tempLen = 0;   //�ҵ��Ļ��������г���
            int k = 0;         //�ҵ��Ļ�����ĸ����
            temp[k++] = str[i];  //�����һ��Ԫ���ǻ��ĵ���ɲ��֣��������temp�����У�k++
            tempLen++;     //���ĳ��ȼ�1
            if (str[i] == str[j]){  //���ַ�ȷʵ�ǻ��ĵ���ɲ���
                tempLen++;        //�����ַ������ȼ�1
                int index1 = i + 1;    //index1ָ������ײ��ĺ�һ��
                int index2 = j - k;    //index2ָ����һ��Ĵ���ĩβ
                while (index1 <= index2){     //������β��Ӧ�еĻ��Ĵ�
                    if (index1 == index2){   //���Ҫ���һ��Ĵ�ֻʣһ���ַ�
                        temp[k++] = str[index1];  //���������ʶ��������
                        tempLen += 1;
                        break;
                    }
                    while (str[index1] != str[index2] && index2 > index1) index2--;  //��β����ʼ���뿪ʼ����ͬ��Ԫ��
                    if (str[index1] == str[index2] && index1 != index2) {   //�ҵ�ֵ��ͬ���±겻ͬ��Ԫ��
                        temp[k++] = str[index1];    //��Ԫ�طŵ�������
                        tempLen += 2;    //���ȼӶ�
                        index2--;  //β����ǰ�ƶ�
                    }
                    else
                        index2 = j - k;  //û���ҵ������ַ���ͬ��Ԫ�أ�β���ƶ�����ʶ��β��λ��
                    index1++;  //�ײ���ǰ�ƶ�
                }
            }
            if (tempLen > ansLen) {   //������ҵ��Ļ������г��ȴ���֮ǰ�ĳ���
                ansLen = tempLen;
                for (int l = 0; l < k; ++l) { //��Ԫ�ظ��Ƶ��������
                    ans[l] = temp[l];
                }
                for (int l = 0; l < tempLen - k; ++l) {
                    ans[l + k] = temp[tempLen - k - l - 1];
                }
                ans[ansLen] = '\0';
            }
        }
    }
    delete [] temp;  //�ͷ�temp����ռ�

    return ans;
}

/**
 * ��̬�滮����������������
 * str Ŀ���ַ���
 * strLen Ŀ���ַ���������
 * dp[i][j]  ��i��j�������������
 * status[i][j]  ���ݾ���ָ�����ݵķ���
 *              1 ��Խ��߻���    i+1,j-1
 *              2 ��ǰ����   i,j-1
 *              3 ���»���   i+1,j
 * @return char*
 */
char* DynProLongest(char *str,int strLen){
    char *ans = new char[strLen];  //�������
    int ansLen = 0;   //���鳤��

    if(strLen < 2) {   //���ԭ�ַ�����С��2
        ans[0] = str[0];
        ans[1] = '\0';
        return ans;
    }

    int dp[MAXSIZE][MAXSIZE];   //�������飬Ԫ�س�ֵȫΪ0
    int status[MAXSIZE][MAXSIZE];   //״̬���飬Ԫ�س�ֵȫΪ0

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
    return ans;
}

/**
 *
 * @return FILE*
 */
FILE* fileRead()
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
    char ch = fgetc(fp);  //�ȶ�ȡһ��Ԫ��
    int i = 0;
    while(ch != EOF && ch != '\n'){   //�ļ���ĩβ���˻��з�
        str[i] = ch;
        ch = fgetc(fp);
        i++;
    }
    str[i] = '\0';
    return ch;
}
/*
void randStr(){
    char str[11];
    int num;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            num =  rand() % 7;
            str[j] = (char)(num + 97);
        }
        str[10]  = '\0';
        cout<<str<<endl;
    }
}*/

int main()
{
    char str[MAXSIZE];
    char ch = ' ';

    FILE *fp = fileRead();   //���ļ�
    if(fp == nullptr){      //���ļ�ʧ��
        printf("����,�ļ��򲻿�,�����ļ���\n");
    }
    else{
        printf(" %s    \t %s\t%s\n","ԭ�ַ���","���������","��̬�滮���");
        while(ch != EOF){   //�ļ�û�ж���ĩβ
            ch = readLine(fp,str);   //ÿ�ζ�ȡһ�У������ݶ���str�ַ�������
            int strLen =strlen(str);   //��ȡ�ַ�������
            char* bfl = BruteForceLongest(str,strLen);  //�����������������������
            char* dpl= DynProLongest(str,strLen);
            printf("%-15s",str);    //���Ŀ���ַ���
            printf("%-15s",bfl);   //����ҵ�������Ĵ�
            printf("%-15s\n",dpl);   //����ҵ�������Ĵ�
            delete [] bfl;
            delete [] dpl;
        }
        fclose(fp);
    }
    return 0;
}

// E:/C++/test.txt