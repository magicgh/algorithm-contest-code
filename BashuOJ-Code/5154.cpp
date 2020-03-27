#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=105;
struct node{int to,val;};
struct heap
{
	int u,dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
int n,m,k;
int c[MAXN],h1[MAXN],h2[MAXN];
double f[485][MAXN];
vector<node>a[MAXN];
bool vst[MAXN][485];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Dijkstra()
{
	double Ans1=0,Ans2=0;
	priority_queue<heap>q;
	q.push((heap){0,0}),f[0][0]=1;
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		int cnt=0;
		if(vst[now.u][now.dist])continue;
		vst[now.u][now.dist]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			int Time=now.dist+c[it->to]+it->val;
			if(vst[it->to][Time])continue;
			if(Time<=k)cnt++;
		}
		Ans1+=((double)f[now.dist][now.u]*(double)h1[now.u]);
		Ans2+=((double)f[now.dist][now.u]*(double)h2[now.u]);
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			int Time=now.dist+c[it->to]+it->val;
			if(Time>k)continue;
			if(vst[it->to][Time])continue;
			f[Time][it->to]+=f[now.dist][now.u]/(double)cnt;
			q.push((heap){it->to,Time});
		}
	}
	printf("%.5lf %.5lf",Ans1,Ans2);
}
int main()
{
	n=GetInt(),m=GetInt(),k=GetInt();
	for(ri i=1;i<=n;i++)
		c[i]=GetInt(),h1[i]=GetInt(),h2[i]=GetInt();
	for(ri i=1;i<=m;i++)
	{
		int x=GetInt(),y=GetInt(),t=GetInt();
		a[x].push_back((node){y,t});	
		a[y].push_back((node){x,t});
	}
	for(ri i=1;i<=n;i++)
		a[0].push_back((node){i,0});
	Dijkstra();
	return 0;
}
