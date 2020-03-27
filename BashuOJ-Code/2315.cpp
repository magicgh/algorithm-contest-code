#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int n,s,f[5005],sum[5005],t[5005];
int main()
{
	n=getint(),s=getint();
	for(int i=1;i<=n;i++)sum[i]=getint(),t[i]=getint();
	for(int i=1;i<=n;i++)sum[i]+=sum[i-1],t[n-i+1]+=t[n-i+2];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)//枚举前j个
	{
		if(!f[i])f[i]=f[j-1]+(s+sum[i]-sum[j-1])*t[j];
		else f[i]=min(f[i],f[j-1]+(s+sum[i]-sum[j-1])*t[j]);//f[i]=f[j-1]+[i,j]区间导致后面增加的费用
	}
		printf("%d",f[n]);
	return 0;	
}

