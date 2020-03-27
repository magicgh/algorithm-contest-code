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
const int MAXN=10000005;
int n,Mob[MAXN],p[MAXN],g[MAXN];
long long Sm[MAXN],ans;
bool vst[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Pretreatment()
{
	Mob[1]=1;
	for(ri i=2;i<MAXN;i++)
	{
		if(!vst[i])p[++p[0]]=i,Mob[i]=-1,g[i]=1;//统计质数前缀Mob 
		for(ri j=1;j<=p[0]&&i*p[j]<MAXN-1;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0){Mob[i*p[j]]=0,g[i*p[j]]=Mob[i];break;}
			Mob[i*p[j]]-=Mob[i],g[i*p[j]]=Mob[i]-g[i];
		}
	}
	for(ri i=1;i<MAXN;i++)Sm[i]=Sm[i-1]+g[i];
}
int main()
{
	Pretreatment();
	n=getint();
	int next=0;
	for(int i=1;i<=n;i=next+1)
	{
		next=n/(n/i);
		ans+=(long long)(n/i)*(long long)(n/i)*(Sm[next]-Sm[i-1]);
	}
	printf("%lld",ans);
	return 0;
}

