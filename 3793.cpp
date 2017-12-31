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
const int MAXN=3005;
const double eps=1e-10;
const int INF=0x7fffffff;
struct Point{int x,y;};
Point a[MAXN];
double List[MAXN];
int n;
ll Ans;
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
inline double GetSlope(const Point &a,const Point &b)
{
	if(a.x-b.x==0)return (double)INF;
	else return double((double)(a.y-b.y)/(double)(a.x-b.x));
}
int main()
{
	n=getint(),Ans=(ll)(n-2)*(ll)(n-1)*(ll)n/6;
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		a[i]=(Point){x,y};
	}
	for(ri i=1;i<n;i++)
	{
		int tot=0;ll cnt=0;
		for(ri j=i+1;j<=n;j++)
			List[++tot]=GetSlope(a[i],a[j]);
		sort(List+1,List+tot+1);
		for(ri j=1;j<=tot;j++)
		{
			int k=j+1;
			while(fabs(List[j]-List[k])<=eps&&k<=tot)k++;
			cnt+=(k-j-1);
		}
		Ans-=cnt;
	}
	printf("%lld\n",Ans);
	return 0;
}
