//Ѱ��������Ӵ�

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
char* BruteForceLongest(char *str,int strLen){
    if(strLen < 2)   //������鳤��С��2��ֱ�ӷ���
        return str;

    int index1,index2;
    int len = 0;      //�ҵ��Ļ��ĳ���
    int start = 0;    //���ĵĿ�ʼ�±�

    for (int i = 0; i < strLen; ++i) {           //�����±�Ϊi���ַ��ǻ��ĵĿ�ʼ�ַ�
        for (int j = i+1; j < strLen; ++j) {    //Ѱ���±�Ϊj������ʼ�ַ���ͬ���ַ�
            if(str[j] == str[i]){   //���
                index1 = i + 1;
                index2 = j - 1;
                while (index1 <= index2){      //�Ƚ���βi��j�м��Ԫ���Ƿ���ͬ
                    if(str[index1] != str[index2]) break;
                    index1++;
                    index2--;
                }
                if(index1 > index2 && ((j - i + 1 )> len)){   //������ݵ��м䣬���Ҵ˴��ҵ��Ļ��ĳ��ȴ���֮ǰ�ĳ���
                    start = i;
                    len = j-i+1;
                }
            }
        }
    }
    if(len > 1) {   //�л���������
        char *res = new char[len+1];    //��̬��������ռ�
        for (int i = 0; i < len; ++i) {    //���ҵ��Ļ������и��Ƶ�����res��
            res[i] = str[i + start];
        }
        res[len] = '\0';     //����������һλ��Ϊ������
        return res;      //���ش���������
    }
    else return nullptr;   //���ؿ�ָ��
}

/**
 * ��̬�滮����������������
 * str Ŀ���ַ���
 * strLen Ŀ���ַ���������
 * dp[i][j]  true ��ʾ��i��j�Ƿ��ǻ���
 *           false ���ǻ���
 * @return char*
 */
char* DynProLongest(char *str,int strLen){
    if(strLen < 2)
        return str;

    int len = 0;      //���ĳ���
    int start = 0;    //���Ŀ�ʼλ��
    bool dp[MAXSIZE][MAXSIZE];     //״̬����

    for(int i = 0; i < MAXSIZE; ++i) {   //��ʼ��״̬���飬ȫ����Ϊfalse
        for (int j = 0; j < MAXSIZE; ++j) {
            dp[i][j] = false;
        }
    }
    for(int i = 0;i < strLen;++i){
        dp[i][i] = true;         //ֻ��һ��Ԫ�ص�ʱ��϶�Ϊtrue
        if((i < strLen - 1) && str[i] == str[i+1])    //���������������ͬ��Ԫ��
            dp[i][i+1] = true;
        for(int j=i-1;j>=0;--j){    //�����ж��Ƿ�Ϊ����
            if((str[i] == str[j]) && dp[i-1][j+1]){   //��βi��j����Ԫ����ȣ���dp[i-1][j+1]�ǻ���
                dp[i][j] = true;     //��i��j�ǻ���
                if((i-j+1)>len) {    //������ҵ��Ļ��ĳ��ȴ���֮ǰ�ҵ��Ļ��ĳ���
                    start = j;       //���Ŀ�ʼ�±�
                    len = i - j + 1;   //���ĳ���
                }
            }
        }
    }
    if(len > 1) {   //�л���������
        char *res = new char[len+1];    //��̬��������ռ�
        for (int i = 0; i < len; ++i) {    //���ҵ��Ļ������и��Ƶ�����res��
            res[i] = str[i + start];
        }
        res[len] = '\0';     //����������һλ��Ϊ������
        return res;      //���ش���������
    }
    else return nullptr;   //���ؿ�ָ��
}

/**
 *
 * @param str  ���Ԫ�ص�����
 * @return FILE*
 */
FILE* fileRead()
{
    //char fname[20];   //���������ļ���
    FILE *fp;    //�ļ�ָ��

    //printf("�������ȡ�ļ���:");
    //scanf("%s",fname);

    fp=fopen("E:\\C++\\test.txt","r");  //���ļ�
    return fp;   //�����ļ�ָ��
}

/**
 * ��ȡһ������
 * @param fp �ļ�ָ��
 * @param str ���������ַ���
 * @return ch
 */
char readLine(FILE* fp,char* str){
    char ch = fgetc(fp);
    int i = 0;
    while(ch != EOF && ch != '\n'){   //�ļ���ĩβ���˻��з�
        str[i] = ch;
        ch = fgetc(fp);
        i++;
    }
    str[i] = '\0';
    return ch;
}

int main()
{
    char str[MAXSIZE];
    char ch = ' ';

    FILE *fp = fileRead();
    if(fp == nullptr){
        printf("����,�ļ��򲻿�,�����ļ���\n");
    }
    else{
        while(ch != EOF){
            ch = readLine(fp,str);
            int strLen =strlen(str);
            char* bfl = BruteForceLongest(str,strLen);  //�����������������������
            if(bfl != nullptr) {
                cout << bfl << endl;
                delete [] bfl;
            }
            else
                cout<<"���ַ����������������!"<<endl;
        }
    }

    /*cout<<"�������ַ�����";
    cin>>str;*/

    /*char* dpl = DynProLongest(str,strLen);     //��̬�滮������������������
    if(dpl != nullptr) {
        cout << dpl << endl;
        delete [] dpl;
    }
    else
        cout<<"���ַ����������������!"<<endl;*/
    return 0;
}