#include <iostream>
#include <string>

#define M 3   //��Դ��������
#define N 5   //���̵ĸ���

using namespace std;

void output(int iMax[N][M],int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N]);
bool safety(int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N]);
bool banker(int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N],int iRequest[M],char name);

int main()
{
	int i,j;

	//��ǰ����ÿ����Դ����Դ��
	int iAvailable[M]={3,3,2};

	//ϵͳ��N�������е�ÿһ�����̶�M����Դ���������
	int iMax[N][M]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	
	//iNeed[N][M]ÿһ����������ĸ�����Դ��
	//iAllocation[N][M]Ϊϵͳ��ÿһ����Դ��ǰ�ѷ����ÿһ���̵���Դ��
	int iNeed[N][M],iAllocation[N][M]={{0,1,1},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};


	int iRequest[M];  //�����������Դ��

	//������
	char cName[N]={'a','b','c','d','e'};

	char name; //�ĸ�����������Դ

	bool bExitFlag=true;   //�˳����
	char ch;			   //����ѡ���Ƿ�����������ʱ��������ֵ
	
	bool bSafe;   //��Ű�ȫ���ı�־
	//����iNeed[N][M]��ֵ
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			iNeed[i][j]=iMax[i][j]-iAllocation[i][j];
		
	output(iMax,iAllocation,iNeed,iAvailable,cName);
	bSafe=safety(iAllocation,iNeed,iAvailable,cName);
	
	//�Ƿ����
	while(bExitFlag)
	{
		cout<<"\n"<<"����������룿\nyΪ�ǣ�nΪ��\n";
		cin>>ch;

		switch(ch)
		{  
		    case 'y':
		        printf("����%d������:",N);
                for (int i = 0; i < N; ++i) {
                    printf("%c  ",cName[i]);
                }
                cout<<endl<<"�ĸ�����������Դ:";
                cin>>name;
                cout<<"�������������Դ����Ŀ:";
                for (int i = 0; i < M; ++i) {
                    cin>>iRequest[i];
                }
                //cout<<"�������м��㷨";
				bSafe=banker(iAllocation,iNeed,iAvailable,cName,iRequest,name);
				if (bSafe)   //��ȫ��������仯�������
					output(iMax,iAllocation,iNeed,iAvailable,cName);
				else{
				    cout<<endl<<"����֮��ϵͳ����ȫ����ֹ����!"<<endl;
				}
				break;
	        case 'n': 
			    cout<<"�˳���\n";
			    bExitFlag=false; 
			    break;
		    default: 
		        cout<<"�����������������룺\n";
		}
	}
}

//���
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
		
		//Availableֻ��Ҫ���һ��
		if (i==0)
			for(j=0;j<M;j++)
				cout<<iAvailable[j]<<"   ";
					
		cout<<endl;
	}	
}

//��ȫ���㷨�����а�ȫ�Լ��
bool safety(int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N])
{
	//��ͬѧ���Լ����
	char alignment[N];  //���̵İ�ȫ����
	int index = 0;
	int i,j;

	int Work[M]; //ϵͳ�ɼ����ṩ����Դ��
	for(i = 0;i<M;i++){ //��ʼֵΪiAvailable
		Work[i] = iAvailable[i];
	}
	
	bool Finish[N]={false,false,false,false,false};  //ÿһ�����̿�����ɵı�־

	int flag = 0; //����ѭ����־������⵽��M��������ɵı�־�����˳�
	int timeOut = 0; //ϵͳ���ܻ��γ�����
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
	    cout<<endl<<"��ǰϵͳ��һ����ȫ����Ϊ:";
		for(i = 0;i<N;i++)
			printf("%c ",alignment[i]);
		printf("\n");
		return true;
	}
	return false;
}

bool banker(int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N],int iRequest[M],char name)
{
	//��ͬѧ���Լ����
	int index,j;
	bool flag = false; //����ɹ���ʧ�ܱ�־
    for (index = 0; index < N; ++index) {
        if (name == cName[index]) break;
    }
    for (j = 0; j < M; ++j) {   //����������Դ��������Ҫ����Դ��������ʧ��
        if(iRequest[j] > iNeed[index][j])
            return false;
    }

    for (j = 0; j < M; ++j) {    //����������Դ�����ڿ�ʹ�õ���Դ������ʧ��
        if(iRequest[j] > iAvailable[j])
            return false;
    }

    //�ٶ����Է���
    for (int i = 0; i < M; ++i) {
        iAvailable[i] = iAvailable[i] - iRequest[i];
        iAllocation[index][i] = iAllocation[index][i] + iRequest[i];
        iNeed[index][i] = iNeed[index][i] - iRequest[i];
    }

    flag = safety(iAllocation,iNeed,iAvailable,cName);
    if(flag){  //�ܲ�����ȫ����
        cout<<"����ɹ�!"<<endl;
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