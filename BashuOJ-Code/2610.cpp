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
int n,cnt,Ans,a[100005],f[100005],g[5];
bool used[1100005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DP(int k)
{
	memset(f,0,sizeof(f));
	f[k]=1,g[1]=g[2]=g[3]=k;
	for(ri i=k+1;i<=n;i++)
	{
		for(ri j=1;j<=3;j++)
			if(abs(a[i]-a[g[j]])!=1&&f[i]<f[g[j]]+1)f[i]=f[g[j]]+1;
		if(abs(a[k]-a[i])!=1&&Ans<f[i])Ans=f[i];//判断开头
		bool bj=0;
		for(ri j=1;j<=3;j++)
			if(a[g[j]]==a[i])g[j]=i,bj=1;//更新前三大的值的位置 
		if(!bj)//替换f[]的三个最大状态中的最小值 
		{
			int t=1;
			if(f[g[t]]>f[g[2]])t=2;
			if(f[g[t]]>f[g[3]])t=3;
			if(f[i]>f[g[t]])g[t]=i;
		}
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)a[i]=getint();
	for(ri i=1;i<=n;i++)
	{
		if(!used[a[i]])
		{
			DP(i),used[a[i]]=1;
			if(++cnt>=3)break;
		}
	}
	printf("%d\n",Ans);
	return 0;
}

