// word-parser.h : ͷ�ļ�
//

#include "string.h"
#include "stdio.h"

char prog[80],token[8],fname[20];
char ch;
int syn,p,m,sum;   //p��ʾ��ǰ��Ҫʶ������������prog��ָ�룻m��token��ָ��
char *rwtab[6]={"begin","if","then","while","do","end"};
FILE *fp;

void scaner()
{
	int n = 0;
	int i = 0;
	for(n=0;n<8;n++)
		token[n]=NULL;
	sum=0;
	ch=prog[p++];
	while(ch==' '||ch == '\n' || ch == '\t')//ÿ��ֻ�жϵ������ַ��Ƿ�ո�
		ch=prog[p++];
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))//ch����ĸ�ַ�
	{	
		syn = 10;
		while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
			token[m++] = ch;
			ch = prog[p++];
		}
		if(ch != ' ')
			p--;
		token[m++] = '\0';
		for(i = 0;i < 6 ;i++){
			if(strcmp(token,rwtab[i]) == 0){
				syn = i + 1;
				break;
			}
		}
	}
	else
		if(ch>='0'&&ch<='9')//ch�������ַ�
		{
			syn = 11;
			while(ch>='0' && ch<='9'){
				sum = sum * 10 + (int)ch - 48;
				ch = prog[p++];
			}
			if(ch != ' ')
				p--;
			token[m++] = '\0';
		}
	else//�����ַ�
	{
		switch(ch)
		{
			case'+': syn=13; token[m++]=ch; break;
			case'-': syn=14; token[m++]=ch; break;
			case'*': syn=15; token[m++]=ch; break;
			case'/': syn=16; token[m++]=ch; break;
			case':': token[m++]=ch;
					 ch = prog[p++];
					 if(ch == '='){
						syn = 18;
						token[m++] = ch;
					 }
					 else {
						syn = 17;
						p--;
					 }
					 break;
			case'<': token[m++]=ch; 
					 ch = prog[p++];
					 if(ch == '='){
						syn = 22;
						token[m++] = ch;
					 }
					 else if(ch == '>'){
						syn = 21;
						token[m++] = ch;
					 }
					 else {
						syn = 20;
						p--;
					 }
					 break;
			case'>': token[m++]=ch; 
					 ch = prog[p++];
					 if(ch == '='){
						syn = 24;
						token[m++] = ch;
					 }
					 else {
						syn = 23;
						p--;
					 }
					 break;
			case'=': syn=25; token[m++]=ch; break;
			case';': syn=26; token[m++]=ch; break;
			case'(': syn=27; token[m++]=ch; break;
			case')': syn=28; token[m++]=ch; break;
			case'#': syn=0; token[m++]=ch; break;
			default:syn=-1;
			}
		token[m]='\0';
	}
}

bool source_code()
{
	char fname[20]; 
	p=0;

	printf("�������������ļ���:"); 
	scanf("%s",fname);
	if((fp=fopen(fname,"r"))==NULL)
	{ 
		printf("����,�ļ��򲻿�,�����ļ���\n"); 
		return false;
	} 
	else
	{ 
		while(!feof(fp))
			{ 
				prog[p]=fgetc(fp); 
				p++; 
			} 
			prog[p]='\0';
			
	}
	return true;
	
}

