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
using namespace std;
int n,cnt,a0,a1,b0,b1,base,x;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int gcd(int t1,int t2){return !t2?t1:gcd(t2,t1%t2);}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		a0=getint(),a1=getint(),b0=getint(),b1=getint(),cnt=0;
		for(ri j=1;j*j<=b1;j++)
		{
			if(b1%j==0)
			{
				int k=b1/j;
				if(gcd(j,a0)==a1&&(j/gcd(j,b0)*b0)==b1)cnt++;
				if(j*j!=b1&&gcd(k,a0)==a1&&(k/gcd(k,b0)*b0)==b1)cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

