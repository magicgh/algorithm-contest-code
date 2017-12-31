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
const int MAXN=100002;
const int INF=0x7fffffff/2;	
bool dir=0;
int n,cnt,a[MAXN];
namespace FastIO
{
    const ll L=1<<3;
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
	n=getint();
	for(ri i=1;i<=n;i++)a[i]=getint();
	(a[1]>a[2])?(a[0]=0,dir=1):(a[0]=INF,dir=0); 
	a[n+1]=(a[n-1]>a[n])?INF:0;
	for(ri i=1;i<=n+1;i++)
	{
		if(a[i]==a[i-1])continue;
		if((a[i]>a[i-1])^dir)cnt++,dir=(a[i]>a[i-1]);		
	}
	printf("%d\n",cnt);
	return 0;
}


