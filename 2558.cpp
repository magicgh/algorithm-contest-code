#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int INF=0x7fffffff;
int N,Ans;
int tx[105],ty[105],belong[105],slack[105];
bool x[105],y[105];
int map[105][105];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline bool DFS(int i,int k)
{
	x[i]=1;
	for(int j=1;j<=N;j++)
	{
		if(y[j])continue;
		if(tx[i]+ty[j]==map[i][j])
		{
			y[j]=1;
			if(!belong[j]||DFS(belong[j],k)){belong[j]=i;return 1;}
		}
		else slack[j]=min(slack[j],(tx[i]+ty[j]-map[i][j])*k);
	}
	return 0;
}
inline void Adjust(int k)
{
	int delta=INF;
	for(int j=1;j<=N;j++)if(!y[j])delta=min(delta,slack[j]);
	for(int i=1;i<=N;i++)if(x[i])tx[i]-=(delta)*k;
	for(int j=1;j<=N;j++){if(y[j])ty[j]+=(delta)*k;else slack[j]-=delta;}
}
void KM(int k)
{
	for(int i=1;i<=N;i++)
	{
		tx[i]=-INF*k;
		for(int j=1;j<=N;j++)tx[i]=max(tx[i],map[i][j]);
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)slack[j]=INF;
		while(true)
		{
			memset(x,0,sizeof(x));
			memset(y,0,sizeof(y));
			if(DFS(i,k))break;
			Adjust(k);
		}
	}
}
int main(){
	N=GetInt();
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)map[i][j]=GetInt();
	KM(-1);
	for(int i=1;i<=N;i++)if(belong[i])Ans+=map[belong[i]][i];
	printf("%d\n",Ans);
	memset(ty,0,sizeof(ty));
	memset(belong,0,sizeof(belong));
	KM(1);
	Ans=0;
	for(int i=1;i<=N;i++)if(belong[i])Ans+=map[belong[i]][i];
	printf("%d",Ans);
	return 0;
}
