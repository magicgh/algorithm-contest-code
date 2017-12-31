#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int Mod=9901;
const int MAXN=500005;
int n,d,m,cnt;
int a[MAXN],b[MAXN],C[MAXN],Ans;
map<int,int>ref;
inline int lowbit(int x){return x&(-x);}
inline void add(int pos,int val)
{
	for(ri i=pos;i<=m;i+=lowbit(i))C[i]+=val;
}
inline int query(int pos)
{
	int ans=0;
	for(ri i=pos;i>0;i-=lowbit(i))ans+=C[i];
	return ans;
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),d=getint();
	for(ri i=1;i<=n;i++)
	{
		b[i]=getint();
		a[++cnt]=b[i],a[++cnt]=b[i]+d,a[++cnt]=b[i]-d;
	}
	sort(a+1,a+cnt+1);
	m=unique(a+1,a+cnt+1)-(a+1);
	for(ri i=1;i<=m;i++)ref[a[i]]=i;
	for(ri i=1;i<=n;i++)
	{
		int val=((query(ref[b[i]+d])-query(ref[b[i]-d]-1))%Mod+Mod)%Mod;
		Ans=(Ans+val)%Mod;
		add(ref[b[i]],val+1);
	}
	printf("%d",Ans);
	return 0;
}

