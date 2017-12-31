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
const int MAXN=1000005;
const int INF=0x7fffffff/2;
int n,m,Q,Slope[5],h[MAXN];
struct Line{int l,r,p,b;};
struct Segment{int s,t;};
struct heap
{
	int pos,b;
	bool operator <(const heap &rhs)
	const {return b>rhs.b;}
}; 
Segment query[MAXN];
Line a[MAXN];
int f[MAXN][21];
bool bj[MAXN];
priority_queue<heap>q;
vector<int>st[MAXN],ed[MAXN];
inline int min(const int &a,const int &b){return a<b?a:b;}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void ST()
{
	memset(f,0x3f,sizeof(f));
	for(ri i=1;i<=n;i++)f[i][0]=h[i];
	for(ri j=1;j<=log2(n);j++)
		for(ri i=1;i+((1<<j)-1)<=n;i++)
		f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
inline int RMQ(int x,int y)
{
	if(x>y)swap(x,y);
	int k=(int)log2(y-x+1);
	return min(f[x][k],f[y-(1<<k)+1][k]);
}
int main()
{
	for(ri i=1;i<=3;i++)Slope[i]=getint();
	n=getint();
	for(ri i=1;i<=n;i++)h[i]=getint();
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		int l=getint(),r=getint(),p=getint(),b=getint();
		a[i]=(Line){l,r,p,b};
		st[l].push_back(i);
		ed[r].push_back(i);
	}
	Q=getint();
	for(ri i=1;i<=Q;i++)
	{
		int s=getint(),t=getint();
		query[i]=(Segment){s,t};
	}
	for(ri Type=1;Type<=3;Type++)
	{
		while(!q.empty())q.pop();
		for(ri i=1;i<=n;i++)
		{
			vector<int>::iterator it;
			for(it=st[i].begin();it!=st[i].end();++it)
			{
				if(a[*it].p==Type)
				{
					bj[*it]=1;
					q.push((heap){*it,a[*it].b});
				}
			}
			while(!q.empty()&&!bj[q.top().pos])q.pop();
			if(!q.empty())h[i]=min(h[i],Slope[Type]*i+q.top().b);
			for(it=ed[i].begin();it!=ed[i].end();++it)
			{
				if(a[*it].p==Type)
					bj[*it]=0;
			} 
		}
	}
	ST();
	for(ri i=1;i<=Q;i++)
		printf("%d\n",RMQ(query[i].s,query[i].t));
	return 0;
}