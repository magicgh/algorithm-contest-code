#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
int n,block[101][101],cnt[101];
bool f[101][10005];
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
	int Min=0x7fffffff;
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int t,s=0;f[i][0]=1;
		while(t=getint())
		{
			if(t==-1)break;
			block[i][++cnt[i]]=t,s+=t;
		}
		Min=min(Min,s);
	}
	for(ri i=1;i<=n;i++)//依次枚举个数 
		for(ri j=1;j<=cnt[i];j++)//01背包 
			for(ri k=Min;k>=block[i][j];k--)f[i][k]=f[i][k]||f[i][k-block[i][j]];
	for(ri i=Min;i>=0;i--)
	{
		bool bj=0;
		for(ri j=1;j<=n;j++)if(!f[j][i]){bj=1;break;}
		if(!bj){printf("%d",i);break;}
		if(i==0)printf("0");
	}
	return 0;
}