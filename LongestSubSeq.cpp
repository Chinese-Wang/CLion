//
// Created by 王京珠 on 2019/12/27.
//

//寻找最长回文子序列

#include <iostream>
#include <cstring>
using namespace std;

#define MAXSIZE 100  //输入字符串最大长度

/**
 * 蛮力法求解最长回文子序列
 * str 目标字符串
 * strLen 目标字符串长度
 * 返回值 找到的最长回文子序列
 * @return  char*
 */
char* BruteForceLongest(const char *str,int strLen) {
    char *ans = new char[strLen];  //结果数组
    int ansLen = 0;   //数组长度

    if(strLen < 2) {
        ans[0] = str[0];
        ans[1] = '\0';
        return ans;
    }

    char *temp = new char[strLen];

    for (int i = 0; i < strLen; ++i) {  //以首字母为回文串开始字符
        for (int j = strLen - 1; j > i; --j) {   //找到与首字母相对应的字符
            int tempLen = 0;   //找到的回文子序列长度
            int k = 0;         //找到的回文字母对数
            temp[k++] = str[i];  //假设第一个元素是回文的组成部分，将其放入temp数组中，k++
            tempLen++;     //回文长度加1
            if (str[i] == str[j]){  //该字符确实是回文的组成部分
                tempLen++;        //回文字符串长度加1
                int index1 = i + 1;    //index1指向回文首部的后一个
                int index2 = j - k;    //index2指向查找回文串的末尾
                while (index1 <= index2){     //查找首尾对应中的回文串
                    if (index1 == index2){   //如果要查找回文串只剩一个字符
                        temp[k++] = str[index1];  //将其放入已识别数组中
                        tempLen += 1;
                        break;
                    }
                    while (str[index1] != str[index2] && index2 > index1) index2--;  //从尾部开始找与开始出相同的元素
                    if (str[index1] == str[index2] && index1 != index2) {   //找到值相同但下标不同的元素
                        temp[k++] = str[index1];    //将元素放到数组中
                        tempLen += 2;    //长度加二
                        index2--;  //尾部向前移动
                    }
                    else
                        index2 = j - k;  //没有找到与首字符相同的元素，尾部移动到已识别尾部位置
                    index1++;  //首部向前移动
                }
            }
            if (tempLen > ansLen) {   //如果新找到的回文序列长度大于之前的长度
                ansLen = tempLen;
                for (int l = 0; l < k; ++l) { //将元素复制到结果数组
                    ans[l] = temp[l];
                }
                for (int l = 0; l < tempLen - k; ++l) {
                    ans[l + k] = temp[tempLen - k - l - 1];
                }
                ans[ansLen] = '\0';
            }
        }
    }
    delete [] temp;  //释放temp数组空间

    return ans;
}

/**
 * 动态规划法求解最长回文子序列
 * str 目标字符串
 * strLen 目标字符除串长度
 * dp[i][j]  从i到j的最长回文子序列
 * status[i][j]  回溯矩阵，指明回溯的方向
 *              1 向对角线回溯    i+1,j-1
 *              2 向前回溯   i,j-1
 *              3 向下回溯   i+1,j
 * @return char*
 */
char* DynProLongest(char *str,int strLen){
    char *ans = new char[strLen];  //结果数组
    int ansLen = 0;   //数组长度

    if(strLen < 2) {   //如果原字符长度小于2
        ans[0] = str[0];
        ans[1] = '\0';
        return ans;
    }

    int dp[MAXSIZE][MAXSIZE];   //长度数组，元素初值全为0
    int status[MAXSIZE][MAXSIZE];   //状态数组，元素初值全为0

    for (int i = strLen-1; i >=0 ; --i){  //从后往前遍历数组
        dp[i][i] = 1;    //单个元素看作是回文
        status[i][i] = 1;  //对角线回溯
        for (int j = i+1; j < strLen ; ++j){
            if(str[i] == str[j]){   //找到两个相同字符
                dp[i][j] = dp[i+1][j-1] + 2;
                status[i][j] = 1;    //向对角线回溯
            }else {   //两个元素值不等
                if (dp[i + 1][j] > dp[i][j - 1]){  //找到其子序列的最大长度
                    dp[i][j] = dp[i + 1][j];
                    status[i][j] = 3;    //向下回溯
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    status[i][j] = 2;   //向前回溯
                }
            }
        }
    }
    int i = 0,j = strLen-1;
    while(i <= j){  //回溯赋值
        if(status[i][j] == 1){   //等于1，代表该字符是回文序列的组成部分
            ans[ansLen++] = str[i];
            i++;
            j--;
        }
        if(status[i][j] == 2) j--;   //向前回溯
        if(status[i][j] == 3) i++;   //向下回溯
    }
    int index = dp[0][strLen-1] - ansLen-1;
    for(i = 0;i < index + 1;i++){  //将回文序列的另一半复制
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
    char fileName[20];   //存放输入的文件名
    FILE *fp;    //文件指针

    printf("请输入读取文件名:");
    scanf("%s", fileName);

    fp=fopen(fileName, "r");  //打开文件
    return fp;   //返回文件指针
}

/**
 * 读取一行数据
 * @param fp 文件指针
 * @param str 保存数据字符串
 * @return char
 */
char readLine(FILE* fp,char* str){
    char ch = fgetc(fp);  //先读取一个元素
    int i = 0;
    while(ch != EOF && ch != '\n'){   //文件到末尾或到了换行符
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

    FILE *fp = fileRead();   //打开文件
    if(fp == nullptr){      //打开文件失败
        printf("错误,文件打不开,请检查文件名\n");
    }
    else{
        printf(" %s    \t %s\t%s\n","原字符串","蛮力法结果","动态规划结果");
        while(ch != EOF){   //文件没有读到末尾
            ch = readLine(fp,str);   //每次读取一行，将数据读到str字符数组中
            int strLen =strlen(str);   //获取字符串长度
            char* bfl = BruteForceLongest(str,strLen);  //蛮力法求解出的最长回文子序列
            char* dpl= DynProLongest(str,strLen);
            printf("%-15s",str);    //输出目标字符串
            printf("%-15s",bfl);   //输出找到的最长回文串
            printf("%-15s\n",dpl);   //输出找到的最长回文串
            delete [] bfl;
            delete [] dpl;
        }
        fclose(fp);
    }
    return 0;
}

// E:/C++/test.txt