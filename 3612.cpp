#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int N,M;
int num[100005]={0};
bool Hash[100005]={0};
int main(){
	N=GetInt();
	for(int i=1;i<=N;i++)
	{
		memset(num,0,sizeof(num));
		M=GetInt();
		for(int j=1;j<=M;j++)
		{
			num[j]=GetInt();
		}
		for(int k=1;;k++)
		{
			bool bj=0;
			memset(Hash,0,sizeof(Hash));
			for(int j=1;j<=M;j++)
			{
			if(Hash[num[j]%k]){bj=1;break;}
			else Hash[num[j]%k]=1;
			}
			if(!bj){printf("%d\n",k);break;}
		}
	}
	return 0;
}
