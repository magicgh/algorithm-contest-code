#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=505;
const int INF=0x7fffffff;
struct node{int x,y,c;};
int N,P,T,M=-INF;
int s,t;
vector<node>edge;
vector<int>g[MAXN];
node a[40005];
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
	int lev[MAXN],gap[MAXN];
	int Ans;
	inline void Init()
	{
		edge.clear();
		for(int i=0;i<=N;i++)g[i].clear();
		memset(lev,0,sizeof(lev));
		memset(gap,0,sizeof(gap));	
	}
	inline void AddEdge(int x,int y,int c)
	{
		edge.push_back({x,y,c});
		edge.push_back({y,x,c});
		g[x].push_back(edge.size()-2);
		g[y].push_back(edge.size()-1);
	}
	int DFS(int now,int f)
	{
		if(now==t)return f;
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
				if(!f||lev[s]==t)return ret;
			}
		}
		if(!(--gap[lev[now]]))lev[s]=t;
		gap[++lev[now]]++;
		return ret;
	}
	int main()
	{
		Ans=0;
		gap[0]=N;
		while(lev[s]<t)Ans+=DFS(s,INF);
		return Ans;
	}
};
SAP S;
inline void BuildGraph(int k)
{
	S.Init();
	s=1,t=N;
	for(int i=1;i<=P;i++)
		if(a[i].c<=k)S.AddEdge(a[i].x,a[i].y,1);
}
int Binary_Search()
{
	int l=1,r=M;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		BuildGraph(mid);
		if(S.main()>=T)r=mid-1;
		else l=mid+1;
	} 
	return l;
}
int main(){
	N=GetInt();P=GetInt();T=GetInt();
	for(int i=1;i<=P;i++)
	{
	int x=GetInt(),y=GetInt(),c=GetInt();
	a[i]={x,y,c};
	M=max(M,a[i].c);
	}
	printf("%d",Binary_Search());
	return 0;
}