#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=200005;
const int INF=0x7fffffff/2; 
struct node{int to,val;};
vector<node>a[MAXN];
int n,Mlen=0,Ans=INF,dist[MAXN],prt[MAXN];
bool vst[MAXN];	
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void BFS(int u)
{
	queue<int>q;
	q.push(u);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(prt[now]==it->to||vst[it->to])continue;
			prt[it->to]=now;
			dist[it->to]=dist[now]+it->val;
			q.push(it->to);
		}
	}
}
void GetMlen()
{
	int Start=1,End=1;
	dist[Start]=0,BFS(Start);
	for(ri i=1;i<=n;i++)if(dist[Start]<dist[i])Start=i;
	memset(prt,0,sizeof(prt));
	dist[Start]=0,BFS(Start);
	for(ri i=1;i<=n;i++)if(dist[End]<dist[i])End=i;
	for(ri i=End;i;i=prt[i])
		Ans=min(Ans,max(dist[Start],dist[End]-dist[i]));
	for(ri i=End;i;i=prt[i])vst[i]=1;
	for(ri i=End;i;i=prt[i])dist[i]=0,BFS(i);
	for(ri i=1;i<=n;i++)Ans=max(Ans,dist[i]);
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back((node){y,1});
		a[y].push_back((node){x,1});
	}
	GetMlen();
	printf("%d",Ans);
	return 0;
}