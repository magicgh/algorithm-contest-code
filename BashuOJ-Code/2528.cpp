#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
struct Query
{
	int x,y;
};
Query A1[41],A2[41];
vector<int>a[2001];
bool vst[2001];
int belong[2001],Num[2001];
int N,P,G[41][41],Ans=0,A1N=0,A2N=0,sN=0;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
inline int abs(int x) 
{
int t=(x>>31);
return (x+t)^t;
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
bool DFS(int x)
{
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(vst[*it])continue;
		vst[*it]=1;
		if(!belong[*it]||DFS(belong[*it]))
		{
			belong[*it]=x;return 1;
		}
	}
	return 0;
}
int main(){
	N=GetInt();
	P=GetInt();
	for(int i=1;i<=P;i++)G[GetInt()][GetInt()]=1;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	{
		if(!G[i][j]&&!((i+j)&1))
		{
		Num[++sN]=(i-1)*N+j;
		for(int k=0;k<=3;k++)
		{
			if(G[i+dx[k]][j+dy[k]])continue;
			if(i+dx[k]>=1&&i+dx[k]<=N&&j+dy[k]>=1&&j+dy[k]<=N)
			a[(i-1)*N+j].push_back((i+dx[k]-1)*N+j+dy[k]);
		}
		}
	}
	for(int i=1;i<=sN;i++)
	{
		memset(vst,0,sizeof(vst));
		if(DFS(Num[i]))Ans++;
	}
	printf(N*N-P==Ans<<1?"Yes\n":"No\n");
	if(N*N-P==Ans<<1)
	{
    for(int i=1;i<=N*N;i++)
	{
		if(!belong[i])continue;
		int pos=min(belong[i],i);
		int y=(pos%N)?pos%N:N,x=(pos-y)/N+1;
		if(abs(belong[i]-i)==1)A2[++A2N]=(Query){x,y};
		else A1[++A1N]=(Query){x,y};
	}
	printf("%d\n",A1N);
	for(int i=1;i<=A1N;i++)printf("%d %d\n",A1[i].x,A1[i].y);
	printf("%d\n",A2N);
	for(int i=1;i<=A2N;i++)printf("%d %d\n",A2[i].x,A2[i].y);
	}
	return 0;
}