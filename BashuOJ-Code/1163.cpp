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
const int MAXN=2000005;
long long k,Mob[MAXN],p[MAXN];
bool vst[MAXN];
inline long long getll()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline long long Check(long long mid)
{
	long long ans=0; 
	for(long long i=1;i<=sqrt(mid);i++)ans+=Mob[i]*(mid/(i*i));
	return mid-ans>=k;//大于k，放小 
}
void Init()
{
	Mob[1]=1;
	for(ri i=2;i<MAXN;i++)
	{
		if(!vst[i])p[++p[0]]=i,Mob[i]=-1;//质数情况 
		for(ri j=1;j<=p[0];j++)
		{
			if(p[j]*i>MAXN-1)break;
			vst[p[j]*i]=1;
			if(i%p[j]==0){Mob[i*p[j]]=0;break;}//合数
			Mob[i*p[j]]-=Mob[i];//莫比乌斯函数的前缀和性质 
		}
	}
}
void Binary()
{
	long long l=0,r=40000000000LL;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld",l);
}
int main()
{
	Init();
	k=getll();
	Binary();
	return 0;
}

