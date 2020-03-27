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
const int MAXN=100005;
const ll INF=1e18;
ll C[30][MAXN],s[MAXN],f[MAXN];
int pos,n,L,R;
ll a,b,c,d;
char ch[MAXN];
deque<int>q,Q;
inline const ll getll()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int lowbit(int &x){return x&(-x);}
inline void Add(int alpha,int pos)
{
	for(ri i=pos;i<=n;i+=lowbit(i))C[alpha][i]++;
}
inline ll Query(int alpha,int pos)
{
	ll ret=0;
	for(ri i=pos;i>=1;i-=lowbit(i))ret+=C[alpha][i];
	return ret;
}
inline ll Check(int l,int r)
{
	ll Max=0;
	for(ri i=1;i<=26;i++)
		Max=max(Max,Query(i,r)-Query(i,l));
	return Max;
}
inline double Slope(int i,int j)
{
	ll ax=s[i],bx=s[j],ay=f[i]+a*s[i]*s[i],by=f[j]+a*s[j]*s[j];
	if(ax==bx)return (ay-by)<=0?INF:-INF;
	return (double)(ay-by)/(double)(ax-bx);
}
inline ll Sqr(ll x){return x*x;}
int main()
{
	n=getint(),a=getll(),b=getll(),c=getll(),d=getll(),L=getint(),R=getint();
	scanf("%s",ch+1);
	for(ri i=1;i<=n;i++)
	{
		ll x=getll();
		s[i]=s[i-1]+x;
	}
	for(ri i=1;i<=n;i++)
		Add(int(ch[i]-96),i);
	for(ri i=1;i<=n;i++)f[i]=INF;
	q.push_back(0);
	for(ri i=1;i<=n;i++)
	{
		while(q.size()>1&&Slope(q.front(),*(++q.begin()))<=2*a*s[i])q.pop_front();
		if(!q.empty())f[i]=min(f[i],f[q.front()]+a*Sqr(s[i]-s[q.front()])+b);
		if(L<=R)
		{
			while(!Q.empty()&&Check(Q.front(),i)>R)Q.pop_front();
			while(pos<i&&Check(pos,i)>=L)
			{
				while(!Q.empty()&&f[Q.back()]-c*s[Q.back()]>=f[pos]-c*s[pos])Q.pop_back();
				Q.push_back(pos),pos++;
			}
			if(!Q.empty())f[i]=min(f[i],f[Q.front()]+c*(s[i]-s[Q.front()])+d);
		}
		printf("%lld\n",f[i]);
		while(q.size()>1&&Slope(*(q.end()-2),q.back())>=Slope(q.back(),i))q.pop_back();
		q.push_back(i);
	}
	return 0;
}

