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
const int MAXN=400005;
const ll p1=29ll,p2=31ll,Mod1=1000000007ll,Mod2=1000000009ll;
struct Hash
{
	ll k1,k2;
	bool operator ==(const Hash &rhs)
	{
		return k1==rhs.k1&&k2==rhs.k2;
	}
};
Hash h[MAXN];
ll H1[MAXN],H2[MAXN],Pow1[MAXN],Pow2[MAXN];
char str[MAXN];
int n,m,cnt;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int GetHash1(int l,int r)
{
	return (H1[r]-H1[l-1]*Pow1[m]%Mod1+Mod1)%Mod1;
}
inline int GetHash2(int l,int r)
{
	return (H2[r]-H2[l-1]*Pow2[m]%Mod2+Mod2)%Mod2;
}
inline bool cmp(const Hash &a,const Hash &b)
{
	return (a.k1==b.k1&&a.k2<b.k2)||a.k1<b.k1;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		char ch;
		while(ch=getchar())if(isalpha(ch))break;
		str[i]=ch;
	}
	Pow1[0]=Pow2[0]=1;
	for(ri i=1;i<=n;i++)
	{
		H1[i]=(H1[i-1]*p1+(str[i]-'a'+1))%Mod1;
		Pow1[i]=(Pow1[i-1]*p1)%Mod1;
	}
	for(ri i=1;i<=n;i++)
	{
		H2[i]=(H2[i-1]*p2+(str[i]-'a'+1))%Mod2;
		Pow2[i]=(Pow2[i-1]*p2)%Mod2;
	}
	for(ri i=1;i<=n-m+1;i++)
		h[i]=(Hash){GetHash1(i,i+m-1),GetHash2(i,i+m-1)};
	sort(h+1,h+n-m+2,cmp);
	cnt=unique(h+1,h+n-m+2)-(h+1);
	printf("%d\n",cnt);
	return 0;
}
