#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=905;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>edge;
vector<int>g[MAXN];
int map[MAXN][MAXN];
struct stone{int x,y;};
stone a[MAXN];
int N,M,K,aN,S=0,T,Lizard;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,int c)
{
	edge.push_back({x,y,c});
	edge.push_back({y,x,0});
	g[x].push_back(edge.size()-2);
	g[y].push_back(edge.size()-1);
}
struct SAP
{
	int Ans;
	int lev[MAXN],gap[MAXN];
	int DFS(int now,int f)
	{
		if(now==T)return f;
		int ret=0,delta;
		for(int i=0;i<g[now].size();i++)
		{
			node& next=edge[g[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1)
			{
				delta=DFS(next.y,min(f,next.c));
				edge[g[now][i]].c-=delta;
				edge[g[now][i]^1].c+=delta;
				ret+=delta;f-=delta;
				if(!f||lev[S]==T)return ret;
			}
		}
		if(!(--gap[lev[now]]))lev[S]=T;
		gap[++lev[now]]++;
		return ret;
	}
	void main()
	{
		gap[0]=T+1;
		while(lev[S]<T)Ans+=DFS(S,INF);
		printf("%d",Lizard-Ans);
	}
};
SAP st;
int main()
{
	N=GetInt();M=GetInt();K=GetInt();
	char c;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)
	{
		while(c=getchar())if(c>='0'&&c<='3')break;
		map[i][j]=c-'0';
		if(!map[i][j])continue;
		a[++aN]={i,j};
		AddEdge((i-1)*M+j,N*M+(i-1)*M+j,map[i][j]);
	}
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)
	{
		while(c=getchar())if(c=='.'||c=='L')break;
		if(c=='L')AddEdge(S,(i-1)*M+j,1),Lizard++;
	}
	T=2*N*M+1;
	for(int i=1;i<=aN;i++)if(a[i].x<=K||a[i].y<=K||a[i].x>=N-K+1||a[i].y>=M-K+1)AddEdge(M*N+(a[i].x-1)*M+a[i].y,T,INF);
	for(int i=1;i<=aN;i++)
	for(int j=1;j<=aN;j++)
	{
		if(i==j)continue;
		int dist=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
		if(dist<=K*K)AddEdge(N*M+(a[i].x-1)*M+a[i].y,(a[j].x-1)*M+a[j].y,INF);
	}
	st.main();
 return 0;
}
