#include <iostream>
#include <string>

#define M 3   //资源的种类数
#define N 5   //进程的个数

using namespace std;

void output(int iMax[N][M],int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N]);
bool safety(int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N]);
bool banker(int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N],int iRequest[M],char name);

int main()
{
	int i,j;

	//当前可用每类资源的资源数
	int iAvailable[M]={3,3,2};

	//系统中N个进程中的每一个进程对M类资源的最大需求
	int iMax[N][M]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	
	//iNeed[N][M]每一个进程尚需的各类资源数
	//iAllocation[N][M]为系统中每一类资源当前已分配给每一进程的资源数
	int iNeed[N][M],iAllocation[N][M]={{0,1,1},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};


	int iRequest[M];  //进程申请的资源数

	//进程名
	char cName[N]={'a','b','c','d','e'};

	char name; //哪个进程申请资源

	bool bExitFlag=true;   //退出标记
	char ch;			   //接收选择是否继续提出申请时传进来的值
	
	bool bSafe;   //存放安全与否的标志
	//计算iNeed[N][M]的值
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			iNeed[i][j]=iMax[i][j]-iAllocation[i][j];
		
	output(iMax,iAllocation,iNeed,iAvailable,cName);
	bSafe=safety(iAllocation,iNeed,iAvailable,cName);
	
	//是否继续
	while(bExitFlag)
	{
		cout<<"\n"<<"继续提出申请？\ny为是；n为否。\n";
		cin>>ch;

		switch(ch)
		{  
		    case 'y':
		        printf("共有%d个进程:",N);
                for (int i = 0; i < N; ++i) {
                    printf("%c  ",cName[i]);
                }
                cout<<endl<<"哪个进程申请资源:";
                cin>>name;
                cout<<"输入申请各类资源的数目:";
                for (int i = 0; i < M; ++i) {
                    cin>>iRequest[i];
                }
                //cout<<"调用银行家算法";
				bSafe=banker(iAllocation,iNeed,iAvailable,cName,iRequest,name);
				if (bSafe)   //安全，则输出变化后的数据
					output(iMax,iAllocation,iNeed,iAvailable,cName);
				else{
				    cout<<endl<<"申请之后系统不安全，禁止申请!"<<endl;
				}
				break;
	        case 'n': 
			    cout<<"退出。\n";
			    bExitFlag=false; 
			    break;
		    default: 
		        cout<<"输入有误，请重新输入：\n";
		}
	}
}

//输出
void output(int iMax[N][M],int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N])
{
	int i,j;

	cout<<"\n\t   Max  \tAllocation\t  Need  \t Available"<<endl;
	cout<<"\tA   B   C\tA   B   C\tA   B   C\t A   B   C"<<endl;

	for(i=0;i<N;i++)
	{	
		cout<<cName[i]<<"\t";
		
		for(j=0;j<M;j++)
			cout<<iMax[i][j]<<"   ";
		cout<<"\t";
		
		for(j=0;j<M;j++)
			cout<<iAllocation[i][j]<<"   ";
		cout<<"\t";

		for(j=0;j<M;j++)
			cout<<iNeed[i][j]<<"   ";
		cout<<"\t";
		cout<<" ";
		
		//Available只需要输出一次
		if (i==0)
			for(j=0;j<M;j++)
				cout<<iAvailable[j]<<"   ";
					
		cout<<endl;
	}	
}

//安全性算法，进行安全性检查
bool safety(int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N])
{
	//请同学们自己完成
	char alignment[N];  //进程的安全序列
	int index = 0;
	int i,j;

	int Work[M]; //系统可继续提供的资源数
	for(i = 0;i<M;i++){ //初始值为iAvailable
		Work[i] = iAvailable[i];
	}
	
	bool Finish[N]={false,false,false,false,false};  //每一个进程可以完成的标志

	int flag = 0; //结束循环标志，当检测到有M个进程完成的标志，就退出
	int timeOut = 0; //系统可能会形成死锁
	int maxTime = N*N*M*M;

	for(i = 0;i < N;i++){
		if(Finish[i] == false){
			for(j = 0;j < M;j++){
				if(iNeed[i][j] > Work[j])
					break;
			}
			if(j == M){
				for(j = 0; j<M;j++)
					Work[j] = Work[j] + iAllocation[i][j];
				Finish[i] = true;
				alignment[index] = cName[i];
				index++;
				flag = 0;
			}
		}
		else{
			flag++;
		}
		if(flag ==  M)
			break;
		if(i == 4)
			i = -1;
		timeOut++;
		if(timeOut == maxTime)
			break;
	}
	if(flag == M){
	    cout<<endl<<"当前系统的一个安全序列为:";
		for(i = 0;i<N;i++)
			printf("%c ",alignment[i]);
		printf("\n");
		return true;
	}
	return false;
}

bool banker(int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N],int iRequest[M],char name)
{
	//请同学们自己完成
	int index,j;
	bool flag = false; //分配成功或失败标志
    for (index = 0; index < N; ++index) {
        if (name == cName[index]) break;
    }
    for (j = 0; j < M; ++j) {   //如果申请的资源数大于需要的资源数则申请失败
        if(iRequest[j] > iNeed[index][j])
            return false;
    }

    for (j = 0; j < M; ++j) {    //如果申请的资源数大于可使用的资源数，则失败
        if(iRequest[j] > iAvailable[j])
            return false;
    }

    //假定可以分配
    for (int i = 0; i < M; ++i) {
        iAvailable[i] = iAvailable[i] - iRequest[i];
        iAllocation[index][i] = iAllocation[index][i] + iRequest[i];
        iNeed[index][i] = iNeed[index][i] - iRequest[i];
    }

    flag = safety(iAllocation,iNeed,iAvailable,cName);
    if(flag){  //能产生安全序列
        cout<<"分配成功!"<<endl;
        return true;
    }
    else{
        for (int i = 0; i < M; ++i) {
            iAvailable[i] = iAvailable[i] + iRequest[i];
            iAllocation[index][i] = iAllocation[index][i] - iRequest[i];
            iNeed[index][i] = iNeed[index][i] + iRequest[i];
        }
    }
	return false;
}