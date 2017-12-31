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
const int MAXN=5005;
const int INF=0x7fffffff/2;
struct path{int x,y,z;};
path a[MAXN];
int n,m,s,t,prt[505];
inline bool cmp(const path &a,const path &b){return a.z<b.z;}
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
inline bool Judge()
{
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)prt[f1]=f2;
	}
	if(getfa(s)==getfa(t))return 0;
	else return 1;
}
void kruskal()
{
	int Max=MAXN,Min=1;
	for(ri i=1;i<=m;i++)
	{
		for(ri j=1;j<=n;j++)prt[j]=j;
		for(ri j=i;j<=m;j++)
		{
			int f1=getfa(a[j].x),f2=getfa(a[j].y);
			if(f1!=f2)prt[f1]=f2;
			if(getfa(s)==getfa(t))
			{
				if((ll)Max*(ll)a[i].z>(ll)Min*(ll)a[j].z)
				Max=a[j].z,Min=a[i].z;
			}
		}
	}
	int base=__gcd(Min,Max);
	int x=Max/base,y=Min/base;
	if(x%y==0)printf("%d",x/y);
	else printf("%d/%d",x,y);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[i]=(path){x,y,z};
	}
	s=getint(),t=getint();
	sort(a+1,a+m+1,cmp);
	if(Judge())printf("IMPOSSIBLE\n");
	else kruskal();
	return 0;
}

