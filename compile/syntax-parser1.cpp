//syntax-parser.cpp－－语法分析器(采用递归下降分析方法)

#include "word-parser.h"

int kk=0;

void expression();

//因子非终结符
void factor()
{
//同学们自己完成
	scaner();
	if(syn == 27){   //"("
	    scaner();
	    expression();
	    if(syn == 28){
	        scaner();
	    } else{
	        printf("错误：缺少\")\"");
	        kk = 1;
	    }
	}
	/*else{
	    printf("错误：表达式错误！");
	    kk = 1;
	}*/
}

//项
void term()
{
//同学们自己完成
    factor();
    while (syn == 15 || syn == 16) {
        scaner();
        factor();
    }
}

//表达式
void expression()
{
//同学们自己完成
    term();
    while (syn == 13 || syn == 14){
        scaner();
        term();
    }
}

//语句，即赋值语句
void statement()
{
//同学们自己完成
    if(syn == 10){  //10 表示变量
        scaner();
        if(syn == 18){ //18 := 赋值符号
            scaner();
            expression();
        }
        else{
            printf("错误：赋值号错误!");
            kk = 1;
        }
    }
    else{
        printf("错误：语句错误！");
        kk = 1;
    }
}

//语句串
void yucu()
{
//同学们自己完成
    statement();
    while (syn == 26){
        scaner();
        statement();
    }
}

//程序
void lrparser()
{
	if(syn==1)//为"begin"
	{
		m=0;
		scaner();
		yucu();
		if(syn==6)//为"end"
		{
			m=0;
			scaner();
			if(syn==0)
			{
				if(kk==0)
					printf("success\n");
			}
			else 
			{
				printf("错误：缺少“#”\n");
				kk=1;
			}
		}
		else 
		{
			if(kk!=1) printf("错误：缺少“end”\n");
			kk=1;
		}
	}
	else
	{
		printf("错误：缺少“begin”\n");
		kk=1;
	}
}


int main()
{
	bool OpenFileSuccess;
	do
	{
		OpenFileSuccess=source_code();
	}while(!OpenFileSuccess);

	printf("%s",prog);
	printf("\n\n");
	p=0;
	
	scaner();
	lrparser();
    return  0;
}



