#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=405;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>Edge;
vector<int>G[MAXN];
int Map[MAXN][MAXN],Q[MAXN][MAXN],prt[MAXN],vst[MAXN];
int N,M,S,T,K,A,Ans;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct SAP
{
	int gap[MAXN],lev[MAXN];
	inline void AddEdge(int x,int y,int c)
	{
		Edge.push_back({x,y,c});
		Edge.push_back({y,x,c});
		G[x].push_back(Edge.size()-2);
		G[y].push_back(Edge.size()-1);
	}
	int DFS(int now,int f){
		if(now==T)return f;
		int delta,ret=0;
		for(int i=0;i<G[now].size();i++){
			node& next=Edge[G[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1){
			delta=DFS(next.y,min(next.c,f));
			Edge[G[now][i]].c-=delta;
			Edge[G[now][i]^1].c+=delta;
			ret+=delta;f-=delta;
			if(!f||lev[S]==N)return ret;
			}
		}
		if(!(--gap[lev[now]]))lev[S]=N;
		gap[++lev[now]]++;
		return ret;
	}
	int main()
	{
		int Ans=0;
		Edge.clear();
		for(int i=1;i<=N;i++)G[i].clear(),gap[i]=0,lev[i]=0;
		for(int i=1;i<=N;i++)
			for(int j=i+1;j<=N;j++)if(Map[i][j])AddEdge(i,j,Map[i][j]);	
		gap[0]=N;
		while(lev[S]<N)Ans+=DFS(S,INF);
		return Ans;
	}	
};
SAP MaxFlow;
void DFS(int x,int k)
{
	vst[x]=k;
	for(int i=0;i<G[x].size();i++)
		if(vst[Edge[G[x][i]].y]!=k&&Edge[G[x][i]].c>0)DFS(Edge[G[x][i]].y,k);
}
void Gusfield()
{
	memset(Q,0x3f,sizeof(Q));
	for(int i=2;i<=N;i++)prt[i]=1;
	for(int i=2;i<=N;i++)
	{
		S=prt[i],T=i;
		int Ans=MaxFlow.main();
		DFS(S,i);
		for(int j=i+1;j<=N;j++)if(vst[j]!=i&&prt[i]==prt[j])prt[j]=i;
		for(int j=1;j<i;j++)Q[i][j]=Q[j][i]=min(Ans,Q[prt[i]][j]);
	}
}
int main()
{
	A=GetInt();
	for(int k=1;k<=A;k++)
	{
		memset(Map,0,sizeof(Map));
		N=GetInt();M=GetInt();
		for(int i=1;i<=M;i++)
		{
			int x=GetInt(),y=GetInt(),c=GetInt();
			Map[x][y]+=c;
			Map[y][x]+=c;
		}
		Gusfield();
		K=GetInt();
		for(int i=1;i<=K;i++)
		{
			int x=GetInt();Ans=0;
			for(int j=1;j<=N;j++)
			for(int l=j+1;l<=N;l++)if(Q[j][l]<=x)Ans++;
			printf("%d\n",Ans);
		}
		printf("\n");
	}
	return 0;
}