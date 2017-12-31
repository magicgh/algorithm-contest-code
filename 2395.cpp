#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=105;
const int INF=0x7fffffff;
struct node{int x,y,c;};
int N,K;
bool Love[MAXN][MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct SAP
{
	vector<node>Edge;
	vector<int>G[MAXN*2]; 
	int S,T,Ans;
	int lev[MAXN*2],gap[MAXN*2];
	inline void Init()
	{
		Edge.clear();
		for(int i=0;i<=T+1;i++)G[i].clear();
		memset(lev,0,sizeof(lev));
		memset(gap,0,sizeof(gap));	
	}
	inline void AddEdge(int x,int y,int c) 
	{
		Edge.push_back((node){x,y,c});
		Edge.push_back((node){y,x,0});
		G[x].push_back(Edge.size()-2);
		G[y].push_back(Edge.size()-1);
	}
	int DFS(int now,int f) 
	{
		if(now==T)return f;
		int ret=0,delta;
		for(int i=0;i<G[now].size();i++)
		{
			node& next=Edge[G[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1)
			{
				delta=DFS(next.y,min(f,next.c));
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
	inline void BuildGraph(int k)
	{
		Init();
		for(int i=1;i<=N;i++)
		{
			AddEdge(S,i,k);
			AddEdge(i,N+i,K);
			AddEdge(2*N+i,3*N+i,K);
			AddEdge(3*N+i,T,k);
			for(int j=1;j<=N;j++)
			{	
			if(Love[i][j])AddEdge(i,3*N+j,1);
			else AddEdge(N+i,2*N+j,1);
			}
		}
	}
	inline int MaxFlow()
	{
		int ans=0;gap[0]=T+1;
		while(lev[S]<T)ans+=DFS(S,INF);
		return ans;
	}
	void Binary_Search() 
	{
		int l=0,r=N;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			BuildGraph(mid);
			if(MaxFlow()>=N*mid)Ans=mid,l=mid+1;
			else r=mid-1; 
		}
	}
	void main()
	{
		S=0,T=4*N+1;
		Binary_Search();
		printf("%d",Ans); 
	} 
};
SAP S;
int main()
{
	N=GetInt();K=GetInt();
	char ch;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			while(ch=getchar())if(ch=='Y'||ch=='N')break;
			if(ch=='Y')Love[i][j]=1;
		}
	S.main();
 return 0;
}

 