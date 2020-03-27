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
const ll Mod=1000000000ll;
int n;
ll f[3005][35],Sum[3005];
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
void Init()
{
	f[0][0]=f[1][1]=1,Sum[1]=1;
	for(ri i=2;i<=3000;i++)
	{
		for(ri j=0;j<i;j++)
			for(ri k=1;k<=20;k++)
			{
				if(f[j][k-1]&&f[i-1-j][k-1])
					f[i][k]=(f[i][k]+f[j][k-1]*f[i-1-j][k-1])%Mod; 
				if(k>=2)
				{
					if(f[j][k-1]&&f[i-1-j][k-2])
						f[i][k]=(f[i][k]+f[j][k-1]*f[i-1-j][k-2])%Mod;	
					if(f[j][k-2]&&f[i-1-j][k-1])
						f[i][k]=(f[i][k]+f[j][k-2]*f[i-1-j][k-1])%Mod;
				}	
			}
		for(ri j=1;j<=20&&j<=i;j++)
			Sum[i]+=f[i][j]; 
		Sum[i]%=Mod;
	} 
}
int main()
{
	Init();
	while(n=getint())
	{
		if(n==0)break;
		printf("%lld\n",Sum[n]);
	}
	return 0;
}


