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
#define rll register long long
#define ll long long
using namespace std;
const int MAXN=500005;
const ll INF=1e18;
int n,tot,pos[MAXN];
ll ret,h[MAXN],num[MAXN],sum[MAXN];
ll C1[MAXN],C2[MAXN];
namespace FastIO
{
	const int L=1<<15;
	char buf[L],*S,*T;
	inline char getchar()
	{
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,L,stdin);
			if(S==T)return EOF;
		}
		return *S++;
	}
	inline const int GetInt()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline const ll GetLL()
	{
		rll num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline void PutLL(ll x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)PutLL(x/10);
	     putchar(x%10+'0');
	}
}
using FastIO::GetInt;
using FastIO::GetLL;
using FastIO::PutLL;
inline int lowbit(const int &x){return x&(-x);}
inline ll min(const ll &a,const ll &b){return a<b?a:b;}
struct Bit
{
	ll C[MAXN];
	inline void Clear()
	{
		fill(C+1,C+500001,INF);
	}
	inline void Add(int pos,ll val,int type)
	{
		if(type)for(ri i=pos;i<=tot;i+=lowbit(i))C[i]=min(C[i],val);
		else for(ri i=pos;i>=1;i-=lowbit(i))C[i]=min(C[i],val);
	}
	inline ll Query(int pos,int type)
	{
		ll ret=INF;
		if(type)for(ri i=pos;i>=1;i-=lowbit(i))ret=min(ret,C[i]);
		else for(ri i=pos;i<=tot;i+=lowbit(i))ret=min(ret,C[i]);
		return ret;
	}
};
Bit c1,c2;
int main()
{
    n=GetInt();
    for(ri i=1;i<=n;++i)num[i]=h[i]=GetLL(),sum[i]=sum[i-1]+abs(h[i]-h[i-1]);
    sort(num+1,num+n+1);
    tot=unique(num+1,num+n+1)-(num+1);
    c1.Clear(),c2.Clear();
    for(ri i=1;i<=n;++i)
    	pos[i]=lower_bound(num+1,num+tot+1,h[i])-num+1;
	c1.Add(1,0,1);//¼ÓÈë±ß½ç
	ret=sum[n];
	for(ri i=2;i<=n;++i)
	{
		ll g=min(c1.Query(pos[i],1)+h[i],c2.Query(pos[i],0)-h[i])+sum[i-1];
		ret=min(ret,g+sum[n]-sum[i]);
		c1.Add(pos[i-1],g-h[i-1]-sum[i],1);
		c2.Add(pos[i-1],g+h[i-1]-sum[i],0);
	} 
	PutLL(ret);
	return 0;
}