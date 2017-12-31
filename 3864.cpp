#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=505;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>Edge;
vector<int>G[MAXN];
int vst[MAXN];
bool f1[MAXN],f2[MAXN];
int N,M,S,T,Ans	;
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
struct SAP
{
	int lev[MAXN],gap[MAXN];
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
	void main()
	{
		gap[0]=T+1;
		while(lev[S]<T)DFS(S,INF);
	}
};
SAP st;
void DFS_S(int x)
{
	vst[x]=1;f1[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		node& j=Edge[G[x][i]];
		if(!vst[j.y]&&j.c>0)DFS_S(j.y);
	}
}	
void DFS_T(int x)
{
	vst[x]=2;f2[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		node& j=Edge[G[x][i]];
		if(vst[j.y]!=2&&Edge[G[x][i]^1].c>0)DFS_T(j.y);
	}
}
int main(){
	N=GetInt();
	M=GetInt();
	S=1,T=N;
	for(int i=1;i<=M;i++)
	{
		int x=GetInt(),y=GetInt(),z=GetInt();
		AddEdge(x,y,z);	
	}
	st.main();
	DFS_S(S);
	DFS_T(T);	
	for(int i=0;i<Edge.size();i+=2)if(f1[Edge[i].x]&&f2[Edge[i].y])Ans++;
	printf("%d",Ans);
	return 0;
}
