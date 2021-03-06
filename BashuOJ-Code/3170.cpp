#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m;
long long s[500005],f[500005],q[500005];
inline long double Slope(int a,int b)
{
	return (f[b]+s[b]*s[b]-f[a]-s[a]*s[a])/(2*s[b]-2*s[a]);
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DP()
{
	f[0]=0;q[1]=0;
	int l=1,r=1;
	for(int i=1;i<=n;i++)
		{
			while(l<r&&Slope(q[l],q[l+1])<s[i])l++;
			f[i]=f[q[l]]+(s[i]-s[q[l]])*(s[i]-s[q[l]])+m;
			while(l<r&&Slope(q[r-1],q[r])>=Slope(q[r],i))r--;
			q[++r]=i;
		}
		printf("%lld\n",f[n]);
}
int main()
{
	while(~(n=GetInt()))
	{
		m=GetInt();
		for(int i=1;i<=n;i++)
		{
			int x=GetInt();
			s[i]=s[i-1]+x;
		}
		DP();
	}
	return 0;
}