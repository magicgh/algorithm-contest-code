#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=35; 
int n,K,Ans,s[MAXN],t[MAXN],a[MAXN][MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
bool Gauss()
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
				now++;//最大主元标号向后推 
		} 
	}
	for(ri i=now;i<=n;i++)
	{
		if(a[i][n+1])return 0;
		Ans<<=1;
	}
	return 1;
}
int main()
{
	K=getint();
	while(K--)
	{
		n=getint(),Ans=1;
		memset(a,0,sizeof(a));
		for(ri i=1;i<=n;i++)s[i]=getint();
		for(ri i=1;i<=n;i++)t[i]=getint();
		for(ri i=1;i<=n;i++)
			a[i][n+1]=s[i]^t[i],a[i][i]=1;
		int x,y;
		while(scanf("%d%d",&x,&y))
		{
			if(x==0&&y==0)break;
			a[y][x]=1;//末操作为行 
		}
		if(!Gauss())printf("Oh,it's impossible~!!\n");
		else printf("%d\n",Ans);
	}
	return 0;
}


