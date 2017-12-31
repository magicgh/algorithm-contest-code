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
const int INF=0x7fffffff/2;
ll Ans[MAXN];
int n,List[MAXN];
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline const int getint()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
}using FastIO::getint;
void Solve(int l,int r)
{
	if(l>r)return;
	int Max=-INF,pos;
	for(ri i=l;i<=r;i++)
		if(Max<List[i])Max=List[i],pos=i;
	int Min=INF,Now=pos+1;
	for(ri i=pos-1;i>=l;i--)//固定左端点 
	{
		Min=min(Min,List[i]);
		while(Now<=r&&List[Now]>=Min)Now++;
		Ans[Max-Min]+=Now-pos;
	}
	Min=INF,Now=pos-1;
	for(ri i=pos+1;i<=r;i++)//固定右端点
	{
		Min=min(Min,List[i]);
		while(Now>=l&&List[Now]>=Min)Now--;
		Ans[Max-Min]+=pos-Now;
	}
	Solve(l,pos-1),Solve(pos+1,r);
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)List[i]=getint();
	Solve(1,n);
	Ans[0]=n;
	for(ri i=1;i<n;i++)Ans[i]+=Ans[i-1];
	for(ri i=0;i<n;i++)printf("%lld\n",Ans[i]);
	return 0;
}
