#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=1005;
const int Point=105;
const int INF=0x7fffffff;
struct node{int x,y;double c;};
struct bin{int x,y;};
vector<node>Edge;
vector<int>G[MAXN];
bin a[MAXN];
bool vst[Point];
int N,M,S,T,U,cnt=0;
double eps;
int Degree[Point];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,double z)
{
	Edge.push_back({x,y,z});
	Edge.push_back({y,x,0});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
struct SAP
{
	int lev[MAXN],gap[MAXN];
	double DFS(int now,double f){
		if(now==T)return f;
		double delta,ret=0;
		for(int i=0;i<G[now].size();i++){
			node& next=Edge[G[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1){
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
	inline void Init()
	{
		Edge.clear();
		for(int i=0;i<=T;i++)G[i].clear();
		memset(lev,0,sizeof(lev));
		memset(gap,0,sizeof(gap));
	}
	int main()
	{
		double Ans=0;
		S=0,T=N+1;gap[0]=T+1;
		while(lev[S]<T)Ans+=DFS(S,INF);
		return Ans;
	}
};
SAP st;
inline void BuildGraph(double k)
{
	st.Init();
	for(int i=1;i<=M;i++)
	{
		AddEdge(a[i].x,a[i].y,1.0);
		AddEdge(a[i].y,a[i].x,1.0);
	}
	for(int i=1;i<=N;i++)
	{
		AddEdge(S,i,double(U));
		AddEdge(i,T,double(U+double(2.0*k))-double(Degree[i]));
	}
}
void Binary_Search()
{
	double l=0,r=M;
	while(r-l>eps)
	{
		double mid=(l+r)/2.0;
		BuildGraph(mid);
		if((double(M*N)-st.main())/2.0>=eps)l=mid;
		else r=mid;
	}
	BuildGraph(l);//对答案l进行建图跑最小割 
	st.main();
}
void DFS(int x)
{
    vst[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		node& next=Edge[G[x][i]];
		if(next.c>0&&!vst[next.y])cnt++,DFS(next.y);
	}
}
int main(){
	N=GetInt(),M=GetInt();
	eps=double(1.0/double(N*N));
	S=0,T=N+1;U=M;
	for(int i=1;i<=M;i++)
	{
		int x=GetInt(),y=GetInt();
		a[i]=((bin){x,y});Degree[x]++,Degree[y]++;
	}
	Binary_Search();
	DFS(S);
	printf("%d",M?cnt:1);
	return 0;
}