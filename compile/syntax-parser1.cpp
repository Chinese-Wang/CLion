//syntax-parser.cpp�����﷨������(���õݹ��½���������)

#include "word-parser.h"

int kk=0;

void expression();

//���ӷ��ս��
void factor()
{
//ͬѧ���Լ����
	scaner();
	if(syn == 27){   //"("
	    scaner();
	    expression();
	    if(syn == 28){
	        scaner();
	    } else{
	        printf("����ȱ��\")\"");
	        kk = 1;
	    }
	}
	/*else{
	    printf("���󣺱��ʽ����");
	    kk = 1;
	}*/
}

//��
void term()
{
//ͬѧ���Լ����
    factor();
    while (syn == 15 || syn == 16) {
        scaner();
        factor();
    }
}

//���ʽ
void expression()
{
//ͬѧ���Լ����
    term();
    while (syn == 13 || syn == 14){
        scaner();
        term();
    }
}

//��䣬����ֵ���
void statement()
{
//ͬѧ���Լ����
    if(syn == 10){  //10 ��ʾ����
        scaner();
        if(syn == 18){ //18 := ��ֵ����
            scaner();
            expression();
        }
        else{
            printf("���󣺸�ֵ�Ŵ���!");
            kk = 1;
        }
    }
    else{
        printf("����������");
        kk = 1;
    }
}

//��䴮
void yucu()
{
//ͬѧ���Լ����
    statement();
    while (syn == 26){
        scaner();
        statement();
    }
}

//����
void lrparser()
{
	if(syn==1)//Ϊ"begin"
	{
		m=0;
		scaner();
		yucu();
		if(syn==6)//Ϊ"end"
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
				printf("����ȱ�١�#��\n");
				kk=1;
			}
		}
		else 
		{
			if(kk!=1) printf("����ȱ�١�end��\n");
			kk=1;
		}
	}
	else
	{
		printf("����ȱ�١�begin��\n");
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



