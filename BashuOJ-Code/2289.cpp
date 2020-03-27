#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int INF=0x7fffffff/2;
const int MAXN=100005;
int n,m,a[MAXN],b[MAXN],f[MAXN];
struct park{int pos,num;};
deque<int>q;
park c[MAXN];
inline bool cmp(const park &x,const park &y)
{
	return (x.pos==y.pos&&x.num<y.num)||(x.pos<y.pos);
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)a[i]=getint();
	for(ri i=1;i<=m;i++)b[i]=getint();
	for(ri i=1;i<=n;i++)
		c[i]=(park){(i+a[i]>n)?n+1:i+a[i],i};
	sort(c+1,c+n+1,cmp);
	for(ri i=1;i<=n;i++)f[i]=INF;
	for(ri i=1;i<=n;i++)if(c[i].pos>n)f[c[i].num]=1;
	for(ri i=n;i>=1;i--)
	{
		if(c[i].pos>n){q.push_back(c[i].num);continue;}
		while(!q.empty()&&q.front()>c[i].pos)q.pop_front();
		f[c[i].num]=min(f[c[i].num],f[q.front()]+1);
		q.push_back(c[i].num);
	}
	for(ri i=1;i<=m;i++)printf("%d ",f[b[i]]);
	return 0;
}

