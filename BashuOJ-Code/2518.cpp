#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=10005;
const int MAXM=20005;
const int INF=0x7fffffff/2;
struct Path{int u,v,w;};
Path a[MAXM],b[MAXM];
int n,k,m;
int prt[MAXN];
int Max=-INF,Min=INF;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Path &a,const Path &b){return a.w<b.w;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
inline bool Check(int Limit)
{
	int cnt=0;
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		if(a[i].w>Limit)break;
		int f1=getfa(a[i].u),f2=getfa(a[i].v);
		if(f1!=f2)prt[f1]=f2,cnt++;
	}
	if(cnt<k)return 0;
	if(cnt>=n-1)return 1;
	for(ri i=1;i<=m;i++)
	{
		if(b[i].w>Limit)break;
		int f1=getfa(b[i].u),f2=getfa(b[i].v);
		if(f1!=f2)prt[f1]=f2,cnt++;
	}
	return cnt>=n-1;
}
inline int Binary()
{
	int l=Min,r=Max;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	n=GetInt(),k=GetInt(),m=GetInt();
	for(ri i=1;i<=m;i++)
	{
		int u=GetInt(),v=GetInt(),c1=GetInt(),c2=GetInt();
		a[i]=(Path){u,v,c1};
		b[i]=(Path){u,v,c2};
		Max=max(Max,max(c1,c2));
		Min=min(Min,min(c1,c2));
	}
	sort(a+1,a+m+1,cmp);
	sort(b+1,b+m+1,cmp);
	printf("%d\n",Binary());
	return 0;
}

