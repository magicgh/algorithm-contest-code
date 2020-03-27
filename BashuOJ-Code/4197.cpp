#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
inline void swap(int *xx,int *yy){(*xx)^=(*yy);(*yy)^=(*xx);(*xx)^=(*yy);}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int GetLL()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
long long a,b,c,d,N,M,Q,p1,p2;
int t[25000005],num[25000005];
bool Hash[25000005]={0};
int main()
{
	num[0]=GetInt();			
	a=GetLL();b=GetLL();
	c=GetLL();d=GetLL();
	N=GetLL();M=GetLL();
	Q=GetLL();
	a%=d,b%=d,c%=d;
	for(int i=1;i<=M*N;i++)
	{
		num[i-1]%=d;
		p1=(a*num[i-1]*num[i-1])%d;
		p2=(b*num[i-1])%d;
		num[i]=(p1+p2+c)%d;
	}
	for(int i=1;i<=M*N;i++)t[i]=i;
	for(int i=1;i<=M*N;i++)swap(t[i],t[num[i]%i+1]);
	for(int i=1;i<=Q;i++)
	{
		p1=GetInt();
		p2=GetInt();
		swap(t[p1],t[p2]);
	}
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)num[t[(i-1)*M+j]]=(i-1)*M+j;
	for(int i=1;i<=M*N;i++)
	{
		if(!Hash[i])
		{
			int x=num[i]/M+1-(num[i]%M==0);
			int y=num[i]-(x-1)*M;
			Hash[i]=1;
			printf("%d ",i);
			for(int j=x-1;j>=1;j--)
			for(int k=y+1;k<=M;k++)
			{
			if(Hash[t[(j-1)*M+k]])break;
			Hash[t[(j-1)*M+k]]=1;
		    }
			for(int j=x+1;j<=N;j++)
			for(int k=y-1;k>=1;k--)
			{
			if(Hash[t[(j-1)*M+k]])break;
			Hash[t[(j-1)*M+k]]=1;
			}
		}
	}
 return 0;
}
