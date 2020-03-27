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
const int MAXN=1000005;
ll a[MAXN],b[MAXN];
ll Ta[5005],Tb[5005];
ll p,q,A,B,C,D,E,F,La,Lb,cnt;
int n,m;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void MakeSeq()
{
	for(ri i=3;i<=n;i++)
		a[i]=((A*a[i-1])%p-(B*a[i-2])%p-C+3*p)%p;
	for(ri i=3;i<=m;i++)
		b[i]=(D*b[i-1]%(p-1)+E*b[i-2]%(p-1)+F)%(p-1);
}
int main()
{
	p=getll(),q=getll();
	n=getint(),a[1]=getll()%p,a[2]=getll()%p,A=getll()%p,B=getll()%p,C=getll()%p;
	m=getint(),b[1]=getll()%(p-1),b[2]=getll()%(p-1),D=getll()%(p-1),E=getll()%(p-1),F=getll()%(p-1);
	MakeSeq();
	for(ri i=1;i<=n;i++)Ta[a[i]]++,La=max(La,a[i]);
	for(ri i=1;i<=m;i++)Tb[b[i]]++,Lb=max(Lb,b[i]);
	for(ll i=0;i<p;i++)
	{
		ll ret=1;
		for(ll j=0;j<p-1;j++)
		{
			if(ret<=q)cnt+=Ta[i]*Tb[j];
			ret=(ret*i)%p;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}