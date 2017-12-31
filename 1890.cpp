#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=20;
int n;
int C[MAXN],P[MAXN],L[MAXN],Min;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Exgcd(int a,int b,int &d,int &x,int &y)
{
	int t;
	if(b==0)d=a,x=1,y=0; 
	else
	{
		Exgcd(b,a%b,d,x,y);
		t=x,x=y,y=t-(a/b)*y;
	}
}
inline bool Solve(int m)
{
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)
		{
			int d,x,y,a=P[i]-P[j],b=m,c=C[j]-C[i];
			Exgcd(a,b,d,x,y);
			if(c%d)continue;
			int Mod=abs(b/d);
			x=((c/d)*x%Mod+Mod)%Mod;
			if(x<=min(L[i],L[j]))return 0;
		}
	return 1;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		C[i]=getint(),P[i]=getint(),L[i]=getint();
		Min=max(Min,C[i]);
	}
	for(int m=Min;;m++)
		if(Solve(m)){printf("%d\n",m);break;}
	return 0;
}

