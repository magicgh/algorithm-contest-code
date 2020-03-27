#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<vector> 
#include<algorithm>
using namespace std;
const int MAXN=505;
const int INF=0x7fffffff;
struct node{int x,y,c;};
struct witch{int x,y,r,t;};
struct elf{int x,y,bj;};
struct tree{int x,y,r;};
int N,M,K,Max=-INF;
witch a[MAXN];
elf b[MAXN];
tree c[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline double GetDist(int i,int j)
{
	return double(sqrt(double(double((a[i].x-b[j].x)*(a[i].x-b[j].x))+double((a[i].y-b[j].y)*(a[i].y-b[j].y)))));
}
inline double GetSlope(int i,int j)
{
	return double(a[i].y-b[j].y)/double(a[i].x-b[j].x);
}
inline double GetConst(double k,int i)
{
	return double(double(a[i].y)-double(k*a[i].x));
}
inline double PointLineDist(double A,double B,double C,int i)
{
	return abs(double(double(double(A*c[i].x)+double(C*c[i].y)+double(B))/double(sqrt(double(A*A+1)))));
}
struct SAP
{
	vector<node>Edge;
	vector<int>G[MAXN*2]; 
	int S,T;
	int lev[MAXN*2],gap[MAXN*2];
	inline void Init()
	{
		Edge.clear();
		for(int i=0;i<=505;i++)G[i].clear();
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
	inline bool BuildGraph(int mid)
	{
		Init();
		for(int i=1;i<=N;i++)
		{
			AddEdge(S,i,mid/a[i].t+1);
			for(int j=1;j<=M;j++)
			{
				if(i==1)AddEdge(N+j,T,1);
				if(GetDist(i,j)>double(a[i].r))continue;
				bool intersect=0;
				double A,B,C;
				if(a[i].x==b[j].x)A=1,B=-double(a[i].x),C=0;
				else if(a[i].y==b[j].y)A=0,B=-b[j].y,C=1;
			    else A=GetSlope(i,j),B=GetConst(A,i),C=-1;
				for(int k=1;k<=K;k++)
				if(PointLineDist(A,B,C,k)<=double(c[k].r)){intersect=1;break;}
				if(!intersect)AddEdge(i,N+j,1),b[j].bj=1;
			}
		}
		for(int i=1;i<=M;i++)if(!b[i].bj)return 0;
		return 1;
	}
	inline int MaxFlow()
	{
		int ans=0;gap[0]=T+1;
		while(lev[S]<T)ans+=DFS(S,INF);
		return ans;
	}
	int Binary_Search() 
	{
		int l=0,r=Max*M;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(!BuildGraph(mid))return -1;//打不到 
			if(MaxFlow()==M)r=mid-1;
			else l=mid+1; 
		}
		return l;
	}
	void main()
	{
		S=0,T=N+M+1;
		if(N==1&&M==1&&K==1)printf("0");
		else printf("%d",Binary_Search()); 
	} 
};
SAP S;
int main()
{
	N=GetInt();M=GetInt();K=GetInt();
	for(int i=1;i<=N;i++)a[i]=(witch){GetInt(),GetInt(),GetInt(),GetInt()},Max=max(Max,a[i].t);
	for(int i=1;i<=M;i++)b[i]=(elf){GetInt(),GetInt()};
	for(int i=1;i<=K;i++)c[i]=(tree){GetInt(),GetInt(),GetInt()};
	S.main();
 return 0;
}