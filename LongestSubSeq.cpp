//
// Created by 王京珠 on 2019/12/27.
//

#include <iostream>
#include <cstring>
using namespace std;

#define MAXSIZE 100  //输入字符串最大长度

/**
 * 蛮力法寻找最长回文子序列
 * @param str 要搜索的数组
 * @param strLen 数组长度
 * @param ans 结果数组
 */
char* BruteForceLongest(const char *str,int strLen,char ans[]) {
    if (strLen < 2) {  //要搜索的字符串长度小于2
        ans[0] = str[0];
        ans[1] = '\0';
        return ans;
    }

    int ansLen = 0;
    char temp[MAXSIZE];   //暂存结果数组

    for (int i = 0; i < strLen; ++i){  //以首字母为回文串开始字符
        for (int j = strLen - 1; j > i; --j) {   //找到与首字母相对应的字符
            if (str[i] == str[j]) {  //该字符确实是回文的组成部分
                int tempLen = 2;        //回文字符串长度为2，最外层的回文字符
                int num = 0;    //已匹配出的回文字符对数
                temp[num++] = str[i];  //将已匹配的回文字符放入数组temp中
                int index1;    //index1指向回文开始处
                int index2;    //index2指向回文串的末尾
                for (int l = 0; l < j - i; ++l) {  //循环j-i次，将每一个字符可能组成的回文都寻找一遍
                    int tempLen1 = tempLen;   //临时变量，暂存tempLen的值
                    int tempIndex1 = i + l + 1;  //临时变量，表示每次开始寻找回文序列时的下标
                    int tempIndex2 = j-1;  //保存上次回文序列已匹配的结束下标
                    int tempNum = num;  //临时变量，暂存已匹配的回文字符对数
                    index1 = tempIndex1;  //子串匹配开始处
                    index2 = tempIndex2; //子串匹配结束处
                    while (index1 <= index2) {     //查找首尾对应中的回文串
                        if (index1 == index2) {   //如果要查找回文串只剩一个字符
                            temp[tempNum++] = str[index1];  //将其放入已识别数组中
                            tempLen1 += 1; //数组长度加一
                            break;
                        }
                        while (str[index1] != str[index2] && index2 > index1) index2--;  //从尾部开始找与开始出相同的元素
                        if (str[index1] == str[index2] && index1 != index2) {   //找到值相同但下标不同的元素
                            temp[tempNum++] = str[index1];    //将元素放到数组中
                            tempLen1 += 2;    //长度加二
                            index2--;  //尾部向前移动
                            tempIndex2 = index2;
                        } else
                            index2 = tempIndex2;  //没有找到与首字符相同的元素，尾部移动到已识别尾部位置
                        index1++;  //首部向前移动
                    }
                    if (tempLen1 > ansLen) {   //如果新找到的回文序列长度大于之前的长度
                        ansLen = tempLen1;
                        for (int copyIndex = 0; copyIndex < tempNum; ++copyIndex) { //将元素复制到结果数组
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
 * 动态规划法求解最长回文子序列
 * @param str 要搜索的字符串
 * @param strLen 字符串长度
 * @param ans 结果数组
 */
void DynProLongest(const char *str,int strLen,char ans[]){
    int ansLen = 0;   //数组长度

    if(strLen < 2) {   //如果原字符长度小于2
        ans[0] = str[0];
        ans[1] = '\0';
        return;
    }
    //长度数组，元素初值全为0，dp[i][j]表示从i到j的字符串中的最长回文子序列的长度
    int dp[MAXSIZE][MAXSIZE];
    //状态数组，指明元素回溯的方向，1 向对角线方向回溯（i+1,j-1）,2 向前回溯（i，j-1），3 向下回溯（i+1，j）
    int status[MAXSIZE][MAXSIZE];

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
}

/**
 * 打开文件，返回文件指针
 * @return FILE*
 */
FILE* fileOpen()
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
    char ch = (char)fgetc(fp);  //先读取一个元素,fgetc()返回值为int，返回读入字符的ASCII码
    int i = 0;
    while(ch != EOF && ch != '\n'){   //文件到末尾或到了换行符
        str[i] = ch;
        ch = (char)fgetc(fp);
        i++;
    }
    str[i] = '\0';
    return ch;
}

int main()
{
    char str[MAXSIZE];  //保存要搜索的字符串
    char bfl[MAXSIZE];  //蛮力法搜索的结果
    char dpl[MAXSIZE];  //动态规划法搜索的结果
    char ch = ' ';  //退出读取文件的标志

    FILE *fp = fileOpen();   //打开文件
    if(fp == nullptr){      //打开文件失败
        printf("错误,文件打不开,请检查文件名\n");
    }
    else{
        printf(" %s    \t %s\t%s\n","原字符串","蛮力法结果","动态规划结果");
        while(ch != EOF){   //文件没有读到末尾
            ch = readLine(fp,str);   //每次读取一行，将数据读到str字符数组中
            int strLen =strlen(str);   //获取字符串长度
            BruteForceLongest(str,strLen,bfl);  //蛮力法求解出的最长回文子序列
            DynProLongest(str,strLen,dpl);
            printf("%-15s",str);    //输出目标字符串
            printf("%-15s",bfl);   //输出找到的最长回文串
            printf("%-15s\n",dpl);   //输出找到的最长回文串
        }
        fclose(fp);
    }
    return 0;
}

// E:/C++/test.txt