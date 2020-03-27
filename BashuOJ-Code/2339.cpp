#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}q[205];
bool vst[205],G[205][205],bj=0;
int belong[205],rec[205];
int N,M,Ans=0,Sans=0,qN=0;
inline bool cmp(node t1,node t2)
{
	return t1.x<t2.x;
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
bool DFS(int i)
{
	for(int j=1;j<=N;j++)
	{
		if(!G[i][j]&&!vst[j])
		{
			vst[j]=1;
			if(!belong[j]||DFS(belong[j]))
			{
				belong[j]=i;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int x,y;
	N=GetInt();
	while(x=GetInt(),y=GetInt(),x!=0,y!=0)G[x][y]=1;
	for(int i=1;i<=N;i++)
	{
		memset(vst,0,sizeof(vst));
		if(DFS(i))Ans++;
	}
	if(Ans!=N)
	{
	printf("none");
	return 0;
	}
	memcpy(rec,belong,sizeof(belong));
	for(int i=1;i<=N;i++)
	{
		Sans=0;
		memset(belong,0,sizeof(belong));
		G[rec[i]][i]=1;
		for(int j=1;j<=N;j++)
		{
		memset(vst,0,sizeof(vst));
		if(DFS(j))Sans++;
		}
		if(Ans!=Sans)q[++qN]={rec[i],i};
		G[rec[i]][i]=0;
	}
	sort(q+1,q+qN+1,cmp);
	for(int i=1;i<=qN;i++)printf("%d %d\n",q[i].x,q[i].y),bj=1;
	if(!bj)printf("none\n");
	return 0;
}
