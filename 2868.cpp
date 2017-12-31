#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#define ri register int
#define ll long long
using namespace std;
map<long long,long long>mmp;
ll y,z,p;
int t,k;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b,ll p)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ret;
}
inline void Exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	ll t;
	if(b==0)d=a,x=1,y=0;
	else
	{
		Exgcd(b,a%b,d,x,y);
		t=x,x=y,y=t-(a/b)*y;
	}
}
inline void Liner (ll a,ll c,ll b)
{
	ll d,x,y;
	Exgcd(a,b,d,x,y);
	if(c%d!=0)printf("Orz, I cannot find x!\n");
	else printf("%lld\n",((x*(c/d))%(b/d)+b/d)%(b/d));
}
void BSGS(ll a,ll b,ll p)
{
	a%=p;
	if(!a&&!b){printf("1\n");return;}
	if(!a){printf("Orz, I cannot find x!\n");return;}
	long long m=ceil(sqrt(p)),t=1;
	mmp.clear();mmp[1]=m+1;
	for(long long i=1;i<m;i++)
	{
		t=t*a%p;
		if(!mmp[t])mmp[t]=i;
	}
	long long tmp=Pow(a,p-m-1,p);t=1;
	for(long long k=0;k<m;k++)
	{
		long long i=mmp[b*t%p];
		if(i){printf("%lld\n",(i==m+1)?k*m:k*m+i);return;}
		t=t*tmp%p;
	}
	printf("Orz, I cannot find x!\n");
}
int main()
{
	while(~(t=getint()))
	{
		k=getint();
		while(t--)
		{
			scanf("%lld%lld%lld",&y,&z,&p);
			if(k==1)printf("%lld\n",Pow(y,z,p));
			if(k==2)Liner(y,z,p);
			if(k==3)BSGS(y,z,p);
		}
	} 
	return 0;
}

