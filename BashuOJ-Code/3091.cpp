#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#define ri register int
using namespace std;
int n,h[205],f[205];
inline int Pow(int b)
{
	int base=2,ans=1;
	while(b)
	{
		if(b&1)ans=ans*base;
		base=base*base;
		b>>=1;
	}
	return ans;
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)h[i]=getint(),f[i]=0x7fffffff/2;
	f[1]=0;
	for(ri i=2;i<=n;i++)
	{
		if(h[i]==h[i-1]+1)f[i]=min(f[i],f[i-1]+1);
		for(ri j=i-2;j>=1;j--)
		{
				int delta=h[j]+Pow(i-1-j);
			for(ri k=i;k<=n;k++)
				if(delta>=h[k])f[k]=min(f[k],f[i-1]+(i-j));
		}
	}
	printf("%d",f[n]==0x7fffffff/2?-1:f[n]);
	return 0;
}


