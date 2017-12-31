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
struct Bag{ll t1,t2;};
Bag List[MAXN];
int T,n;
ll v,Newv;
bool Flag;
inline const ll getll()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Bag &a,const Bag &b)
{
	if((a.t1<a.t2)^(b.t1<b.t2))
		return a.t2-a.t1>b.t2-b.t1;
	if(a.t1<a.t2)
		return a.t1<b.t1;
	else return a.t2>b.t2;
}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	T=getint();
	while(T--)
	{
		n=getint(),Newv=v=getll();
		Flag=0;
		for(ri i=1;i<=n;i++)
		{
			ll t1=getll(),t2=getll();
			List[i]=(Bag){t1,t2};
		}	
		sort(List+1,List+n+1,cmp);
		for(ri i=1;i<=n;i++)
		{
			v-=List[i].t1;
			if(v<0){Flag=1;break;}
			v+=List[i].t2;
		}
		if(Flag)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
