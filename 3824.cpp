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
int n,m,k,x;
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
inline int Pow(int a,int b)
{
	int ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%n;
		base=(base*base)%n;
		b>>=1;
	}
	return ret%n;
}
int main()
{
	n=getint(),m=getint(),k=getint(),x=getint();
	printf("%d\n",(m*Pow(10,k)+x)%n);
	return 0;
}