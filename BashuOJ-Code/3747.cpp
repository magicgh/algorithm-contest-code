#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=20005;
const int INF=0x7fffffff;
struct node{int x,y;long long c;};
node map[MAXN];
vector<node>Edge;
vector<int>G[MAXN];
int N,M,S,T;
long long K;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,long long c)
{
	Edge.push_back({x,y,c});
	Edge.push_back({y,x,0});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
struct SAP
{
	long long Ans;
	int gap[MAXN],lev[MAXN];
	long long DFS(int now,long long f)
	{
		if(now==T)return f;
		long long ret=0,delta;
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
		gap[0]=N;
		while(lev[S]<T)Ans+=DFS(S,INF);
		printf("%lld\n%lld",Ans/K,Ans%K);
	}
};
SAP st;
int main(){
	N=GetInt();M=GetInt();
	S=1,T=N;
	for(int i=1;i<=M;i++)map[i]={GetInt(),GetInt(),GetInt()},K+=map[i].c;
	for(int i=1;i<=M;i++)AddEdge(map[i].x,map[i].y,map[i].c*K+1);
	st.main();
	return 0;
}
