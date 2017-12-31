#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<bitset>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
int n,m,a[40][40],x[40],Min=0x7fffffff/2,cnt;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Gauss()
{
	int now=1,l;
	for(ri i=1;i<=n;i++)//对于每一行 
	{
		for(l=now;l<=n;l++)
			if(a[l][i])break;//寻找最大主元
		if(l<=n)
		{
			if(now!=l)
				for(ri k=1;k<=n+1;k++)swap(a[now][k],a[l][k]);//交换
			for(ri j=1;j<=n;j++)
				if(j!=now&&a[j][i])
					for(ri k=1;k<=n+1;k++)
						a[j][k]^=a[now][k];//消元
		} 
		now++;
	}
}
void DFS(int now)
{
	if(cnt>Min)return;
	if(!now)
	{
		Min=min(Min,cnt);
		return;
	}
	if(a[now][now])//如果不是自由元 
	{
		int ans=a[now][n+1];
		for(ri i=now+1;i<=n;i++)
			if(a[now][i])ans^=x[i];//回代求解
		x[now]=ans;
		if(ans)cnt++;//ans>0表示按 
		DFS(now-1);
		if(ans)cnt--;
	}
	else//如果是自由元 枚举按与不按两种情况 
	{
		x[now]=0;DFS(now-1);cnt++;
		x[now]=1;DFS(now-1);cnt--;
	}
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		a[i][i]=a[i][n+1]=1;
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		a[x][y]=a[y][x]=1;
	}
	Gauss(),DFS(n);
	printf("%d\n",Min);
	return 0;
}
