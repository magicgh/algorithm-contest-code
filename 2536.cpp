#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=1205;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>edge;
vector<int>g[MAXN]; 
int pig[MAXN],last[MAXN];
int N,M;
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
	int S,T,Ans;
	int lev[MAXN],gap[MAXN];
	inline void AddEdge(int x,int y,int c)
	{
		edge.push_back({x,y,c});
		edge.push_back({y,x,0});
		g[x].push_back(edge.size()-2);
		g[y].push_back(edge.size()-1);
	}
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
		S=1,T=N+2; 
		gap[0]=N+2;
		while(lev[S]<T)Ans+=DFS(S,INF);
		printf("%d",Ans);
	}
};
SAP S;

int main(){
	M=GetInt();N=GetInt();
	for(int i=1;i<=M;i++)pig[i]=GetInt();
	for(int i=1;i<=N;i++)
	{
		int key=GetInt();
		for(int j=1;j<=key;j++)
		{
			int p=GetInt();
			if(!last[p])S.AddEdge(1,i+1,pig[p]),last[p]=i;//第一个客户先选
			else S.AddEdge(last[p]+1,i+1,INF);//第一个客户把交易转移给下一客户 
		}
		/*这里的建模很经典,类似于商品的流通*/ 
		S.AddEdge(i+1,N+2,GetInt());//客户连接汇点 
	}
	S.main();
	return 0;
}