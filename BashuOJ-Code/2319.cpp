#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
inline long long getint()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
long long n,l,weight,w[1005],v[1005];
double f[1005];
int main()
{
	weight=getint();
	l=getint();
	n=getint();
	memset(f,0x7f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)w[i]=getint(),v[i]=getint();
	for(int i=1;i<=n;i++)
	{
		long long WS=0;double VS=0x7fffffff;
		for(int j=1;j<=i;j++)//选前j辆 
		{
			WS+=w[i-j+1];
			if(WS>weight)break;
			VS=min((double)v[i-j+1],VS);
			f[i]=min(f[i],f[i-j]+l/VS);
		}
	}
	printf("%.1lf",f[n]*60);
	return 0;
}

