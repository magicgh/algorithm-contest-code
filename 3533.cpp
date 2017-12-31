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
const int MAXN=1e6+5;
struct classroom{int d,s,t;};
classroom a[MAXN];
int n,m,r[MAXN];
ll temp[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int days)
{
	ll Ans=0;
	memset(temp,0,sizeof(temp));
	for(ri i=1;i<=days;i++)
		temp[a[i].s]+=(ll)a[i].d,temp[a[i].t+1]-=(ll)a[i].d;
	for(ri i=1;i<=n;i++)
	{
		Ans+=temp[i];
		if(Ans>r[i])return 0;
	}
	return 1;
}
void Binary()
{
	int l=0,r=m,Ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(!Check(mid))Ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(!Ans)printf("0\n");
	else printf("-1\n%d\n",Ans);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)r[i]=getint();
	for(ri i=1;i<=m;i++)
	{
		int d=getint(),s=getint(),t=getint();
		a[i]=(classroom){d,s,t};
	}
	Binary();
	return 0;
}

