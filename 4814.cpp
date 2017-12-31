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
const int MAXN=2005;
struct node{int x,y,z;};
node a[2005*2005];
int n,cnt,k,point[MAXN],prt[MAXN];
long long ans;
inline bool cmp(const node &a,const node &b){return a.z>b.z;}
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
void Kruskal()
{
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=cnt;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f2]=f1;
			ans=ans+(long long)a[i].z;
			if(++k==n-1)break;
		}
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
		point[i]=getint();
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)
			a[++cnt]=(node){i,j,(point[i]^point[j])};
	sort(a+1,a+cnt+1,cmp);
	Kruskal();
	printf("%lld",ans);
	return 0;
}

