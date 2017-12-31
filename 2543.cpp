#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=205;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>Edge;
vector<int>G[MAXN];
bool vst[MAXN],get[MAXN];
int N,M,S,T,Total,Ans;
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
	Edge.push_back({x,y,c});
	Edge.push_back({y,x,0});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
void DFS(int x)
{
	vst[x]=1;get[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		node& next=Edge[G[x][i]];
		if(next.c>0&&!vst[next.y])DFS(next.y);
	}
}
struct SAP
{
	int lev[MAXN],gap[MAXN];
	int DFS(int now,int f)
	{
		if(now==T)return f;
		int delta,ret=0;
		for(int i=0;i<G[now].size();i++)
		{
			node& next=Edge[G[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1)
			{
			delta=DFS(next.y,min(next.c,f));
			Edge[G[now][i]].c-=delta;
			Edge[G[now][i]^1].c+=delta;
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
	}
};
SAP st;
int main(){
	M=GetInt();
	N=GetInt();
	S=0,T=M+N+1;
	for(int i=1;i<=M;i++)
	{
		int income=GetInt();Total+=income;
		AddEdge(S,i,income);
		while(true)
		{
			int j=GetInt();
			if(!j)break;
			AddEdge(i,M+j,INF);
		}
	}
	for(int i=1;i<=N;i++)AddEdge(M+i,T,GetInt());
	st.main();
	DFS(S);
	for(int i=1;i<=M;i++)if(get[i])printf("%d ",i);
	printf("\n");
	for(int i=M+1;i<=M+N;i++)if(get[i])printf("%d ",i-M);
	printf("\n");
	printf("%d\n",Total-Ans);
	return 0;
}
