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
const int MAXN=500005;
const int INF=0x7fffffff/2; 
struct node{int to,val;};
vector<node>a[MAXN];
int n,s,Mlen=0,Ans=INF,dist[MAXN],prt[MAXN];
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
	int i,j=End;
	for(i=End;i;i=prt[i])//双指针维护 
	{
		for(;prt[j]&&dist[i]-dist[prt[j]]<=s;j=prt[j]);//找到小于s的最大的偏心距->直径支路 
		Ans=min(Ans,max(dist[j],dist[End]-dist[i]));
	}
	for(i=End;i;i=prt[i])vst[i]=1;
	for(i=End;i;i=prt[i])dist[i]=0,BFS(i);//核上每个结点的子树的最大距离
	for(ri i=1;i<=n;i++)Ans=max(Ans,dist[i]);//路径长度≤s的 每个节点子树的最深的距离
}
int main()
{
	n=getint(),s=getint();
	for(ri i=1;i<n;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	GetMlen();
	printf("%d",Ans);
	return 0;
}
