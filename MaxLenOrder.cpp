//寻找最长回文子串

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
char* BruteForceLongest(char *str,int strLen){
    if(strLen < 2)   //如果数组长度小于2，直接返回
        return str;

    int index1,index2;
    int len = 0;      //找到的回文长度
    int start = 0;    //回文的开始下标

    for (int i = 0; i < strLen; ++i) {           //假设下标为i的字符是回文的开始字符
        for (int j = i+1; j < strLen; ++j) {    //寻找下标为j的与起始字符相同的字符
            if(str[j] == str[i]){   //相等
                index1 = i + 1;
                index2 = j - 1;
                while (index1 <= index2){      //比较首尾i，j中间的元素是否相同
                    if(str[index1] != str[index2]) break;
                    index1++;
                    index2--;
                }
                if(index1 > index2 && ((j - i + 1 )> len)){   //如果回溯到中间，并且此次找到的回文长度大于之前的长度
                    start = i;
                    len = j-i+1;
                }
            }
        }
    }
    if(len > 1) {   //有回文子序列
        char *res = new char[len+1];    //动态开辟数组空间
        for (int i = 0; i < len; ++i) {    //将找到的回文序列复制到数组res中
            res[i] = str[i + start];
        }
        res[len] = '\0';     //把数组的最后一位置为结束符
        return res;      //返回创建的数组
    }
    else return nullptr;   //返回空指针
}

/**
 * 动态规划法求解最长回文子序列
 * str 目标字符串
 * strLen 目标字符除串长度
 * dp[i][j]  true 表示从i到j是否是回文
 *           false 不是回文
 * @return char*
 */
char* DynProLongest(char *str,int strLen){
    if(strLen < 2)
        return str;

    int len = 0;      //回文长度
    int start = 0;    //回文开始位置
    bool dp[MAXSIZE][MAXSIZE];     //状态数组

    for(int i = 0; i < MAXSIZE; ++i) {   //初始化状态数组，全部置为false
        for (int j = 0; j < MAXSIZE; ++j) {
            dp[i][j] = false;
        }
    }
    for(int i = 0;i < strLen;++i){
        dp[i][i] = true;         //只有一个元素的时候肯定为true
        if((i < strLen - 1) && str[i] == str[i+1])    //如果有两个连续相同的元素
            dp[i][i+1] = true;
        for(int j=i-1;j>=0;--j){    //回退判断是否为回文
            if((str[i] == str[j]) && dp[i-1][j+1]){   //首尾i、j两个元素相等，且dp[i-1][j+1]是回文
                dp[i][j] = true;     //从i到j是回文
                if((i-j+1)>len) {    //如果新找到的回文长度大于之前找到的回文长度
                    start = j;       //回文开始下标
                    len = i - j + 1;   //回文长度
                }
            }
        }
    }
    if(len > 1) {   //有回文子序列
        char *res = new char[len+1];    //动态开辟数组空间
        for (int i = 0; i < len; ++i) {    //将找到的回文序列复制到数组res中
            res[i] = str[i + start];
        }
        res[len] = '\0';     //把数组的最后一位置为结束符
        return res;      //返回创建的数组
    }
    else return nullptr;   //返回空指针
}

/**
 *
 * @param str  存放元素的数组
 * @return FILE*
 */
FILE* fileRead()
{
    //char fname[20];   //存放输入的文件名
    FILE *fp;    //文件指针

    //printf("请输入读取文件名:");
    //scanf("%s",fname);

    fp=fopen("E:\\C++\\test.txt","r");  //打开文件
    return fp;   //返回文件指针
}

/**
 * 读取一行数据
 * @param fp 文件指针
 * @param str 保存数据字符串
 * @return ch
 */
char readLine(FILE* fp,char* str){
    char ch = fgetc(fp);
    int i = 0;
    while(ch != EOF && ch != '\n'){   //文件到末尾或到了换行符
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
        printf("错误,文件打不开,请检查文件名\n");
    }
    else{
        while(ch != EOF){
            ch = readLine(fp,str);
            int strLen =strlen(str);
            char* bfl = BruteForceLongest(str,strLen);  //暴力法求解出的最长回文子序列
            if(bfl != nullptr) {
                cout << bfl << endl;
                delete [] bfl;
            }
            else
                cout<<"该字符串无最长回文子序列!"<<endl;
        }
    }

    /*cout<<"请输入字符串：";
    cin>>str;*/

    /*char* dpl = DynProLongest(str,strLen);     //动态规划法求出的最长回文子序列
    if(dpl != nullptr) {
        cout << dpl << endl;
        delete [] dpl;
    }
    else
        cout<<"该字符串无最长回文子序列!"<<endl;*/
    return 0;
}