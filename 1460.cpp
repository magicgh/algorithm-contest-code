#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int INF=0x7fffffff;
struct node{int x,y;};
node a[25],b[25];
int N;
int belong[25];
bool x[25],y[25];
double tx[25],ty[25],map[25][25],slack[25],Ans;
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
		if(abs(tx[i]+ty[j]-map[i][j])<1e-5)
		{
			y[j]=1;
			if(not belong[j] or DFS(belong[j],k)){belong[j]=i;return true;}
		}
		else slack[j]=min(slack[j],(tx[i]+ty[j]-map[i][j])*k);
	}
	return false;
}
inline void Adjust(int k)
{
	double delta=INF;
	for(int j=1;j<=N;j++)if(not y[j])delta=min(delta,slack[j]);
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
	for(int i=1;i<=N;i++)a[i]={GetInt(),GetInt()};
	for(int i=1;i<=N;i++)b[i]={GetInt(),GetInt()};
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)map[i][j]=sqrt(double((a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y)));
	KM(-1);
	for(int i=1;i<=N;i++)if(belong[i])Ans+=map[belong[i]][i];
	printf("%.3lf",Ans);
	return 0;
}
