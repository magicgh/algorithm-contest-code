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
const int MAXN=5005;
struct Point{int x,y;};
Point a[MAXN];
int p,w,n,Ans;
int x[MAXN],y[MAXN];
bool map[MAXN][MAXN];
int h[MAXN],l[MAXN],r[MAXN];
namespace FastIO
{
    const ll L=1<<10;
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
int main()
{
	p=getint(),w=getint(),n=getint();
	for(ri i=1;i<=n;i++)
	{
		x[i]=getint(),y[i]=getint();
		a[i]=(Point){x[i],y[i]};
	}
	x[n+1]=0,y[n+1]=0;
	x[n+2]=p,y[n+2]=w;
	sort(x+1,x+n+3),sort(y+1,y+n+3);
	int Xn=unique(x+1,x+n+3)-(x+1);
	int Yn=unique(y+1,y+n+3)-(y+1);
	for(ri i=1;i<=n;i++)
	{
		int tx=lower_bound(x+1,x+Xn+1,a[i].x)-x;
		int ty=lower_bound(y+1,y+Yn+1,a[i].y)-y;
		map[tx][ty]=1;
	}
	for(ri i=1;i<=Yn;i++)
		l[i]=0,r[i]=w,h[i]=0;
	for(ri i=2;i<=Xn;i++)
	{
		int lastl=0;	
		for(ri j=1;j<=Yn;j++)
		{
			if(!map[i-1][j])
			{
				h[j]+=x[i]-x[i-1];
				l[j]=max(l[j],lastl);
			}
			else 
			{
				h[j]=x[i]-x[i-1];
				l[j]=0,r[j]=w,lastl=y[j];
			}
		}
		int lastr=w;
		for(ri j=Yn;j>=1;j--)
		{
			r[j]=min(r[j],lastr);
			Ans=max(Ans,h[j]*(r[j]-l[j]));
			if(map[i-1][j])lastr=y[j];
		}
	}
	for(ri i=2;i<=Xn;i++)
		Ans=max(Ans,p*(y[i]-y[i-1]));
	printf("%d",Ans);
	return 0;
}
