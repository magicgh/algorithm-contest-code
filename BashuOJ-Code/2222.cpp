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
const int MAXN=50005;
const int Mod=10007;
int n,m,Sum,Len,Ans,L[MAXN],sum[MAXN],f[MAXN][2];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int Max)
{
	int s=0,cnt=0;
	for(ri i=1;i<=n;i++)
	{
		s+=L[i];
		if(s>Max)s=L[i],cnt++;
		if(cnt>m||L[i]>Max)return 0;
	}
	return 1;
	
}
int Binary()
{
	int l=0,r=Sum;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
void DP()
{
	int now=0,next=1;
	for(ri i=1;i<=n;i++)
		if(sum[i]<=Len)f[i][now]=1;//初始化
	Ans=((Ans+f[n][next])%Mod+Mod)%Mod;//不切也要算 
	for(ri j=1;j<=m;j++)//每一次切割 
	{
		int k=1,s=0;
		for(ri i=1;i<=n;i++)
		{
			while(k<i&&sum[i]-sum[k]>Len)
			{
				s=((s-f[k][now])%Mod+Mod)%Mod; 
				k++;
			}
			f[i][next]=s;
			s=((s+f[i][now])%Mod+Mod)%Mod; 
		}
		Ans=((Ans+f[n][next])%Mod+Mod)%Mod;
		now=next,next^=1;
	}
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		L[i]=getint(),Sum+=L[i];
	for(ri i=1;i<=n;i++)sum[i]=sum[i-1]+L[i];
	Len=Binary();
	DP();
	printf("%d %d",Len,Ans);
	return 0;
}

