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
using namespace std;
struct graph{int s,t,v;};
graph a[100005];
int prt[100005],s[100005];
int n;
long long sum=0;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
inline bool cmp(const graph &x,const graph &y){return x.v<y.v;}
void Kruskal()
{
	sort(a+1,a+n+1,cmp);
	for(ri i=1;i<=n;i++)
	{
		int f1=getfa(a[i].s),f2=getfa(a[i].t);
		if(f1==f2)continue;
		sum+=(long long)(s[f1]*s[f2]-1)*(a[i].v+1);
		prt[f1]=f2;
		s[f2]+=s[f1];
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int s=getint(),t=getint(),d=getint();
		a[i]=(graph){s,t,d},sum+=d;
	}
	for(ri i=1;i<=n;i++)prt[i]=i,s[i]=1;
	Kruskal();
	printf("%lld",sum);
	return 0;
}

