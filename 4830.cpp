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
const int MAXN=1005;
const int INF=0x7fffffff;
struct node{int u;ll val;};
node a[MAXN];
vector<int>Edge[MAXN];
int n,e;
ll dist[MAXN][MAXN],f[MAXN],Ans;
bool ext[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const node &a,const node &b){return a.val<b.val;}
void SPFA(int p)
{
	queue<int>q;
	for(ri i=1;i<=n;i++)dist[p][i]=INF,ext[i]=0;
	dist[p][p]=0,q.push(p),ext[p]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop();ext[now]=0;
		vector<int>::iterator it;
		for(it=Edge[now].begin();it!=Edge[now].end();++it)
		{
			if(dist[p][now]+1<dist[p][*it])
			{
				dist[p][*it]=dist[p][now]+1;
				if(!ext[*it])q.push(*it),ext[*it]=1;
			}
		}
	}
}
int main()
{
	n=getint(),e=getint();	
	for(ri i=1;i<=n;i++)
	{
		int w=getint(),m=getint();
		a[i]=(node){i,w};
		for(ri j=1;j<=m;j++)
			Edge[i].push_back(getint());
	}
	for(ri p=1;p<=n;p++)SPFA(p);
	sort(a+1,a+n+1,cmp);
	f[1]=a[1].val;
	for(ri i=2;i<=n;i++)
	{
		f[i]=a[i].val;
		for(ri j=1;j<=n;j++)
			if(a[i].val>a[j].val&&dist[a[i].u][a[j].u]!=INF)
				f[i]=max(f[i],f[j]+a[i].val-e*dist[a[i].u][a[j].u]);
				//从i点出发和由j到i取一个最大值
	}
	for(ri i=1;i<=n;i++)Ans=max(Ans,f[i]);
	printf("%lld\n",Ans);
	return 0;
}


