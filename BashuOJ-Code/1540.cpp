#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#define uint long long
using namespace std;
uint n,x,f[30][155],ans,base=1;
inline uint Getuint()
{
	uint num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=Getuint(),x=Getuint();
	f[0][0]=1;
	for(uint i=1;i<=n;i++)
	{
		base*=6;
		for(uint j=i;j<=i*6;j++)
			for(uint k=1;k<=6;k++)f[i][j]+=f[i-1][j-k];
	}
	for(uint i=x;i<=n*6;i++)ans+=f[n][i];
	uint div=__gcd(ans,base);
	if(!ans)printf("0\n");
	else if(ans==base)printf("1\n");
	else printf("%lld/%lld",ans/div,base/div);
	return 0;
}

