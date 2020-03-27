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
const int MAXN=1000005;
int n,m,ans,color[MAXN],a[MAXN],f[MAXN],cnt;
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
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint();
		if(!color[x])color[x]=++cnt;
		a[i]=color[x];//离散化 
	}
	char ch;
	for(ri i=1;i<=m;i++)
	{
		while(ch=getchar())
			if(ch=='Q'||ch=='R')break;
		if(ch=='R')
		{
			int p=getint(),col=getint();
			if(!color[col])color[col]=++cnt;
			a[p]=color[col];
		}
		if(ch=='Q')
		{
			int l=getint(),r=getint();ans=0;
			for(ri j=l;j<=r;j++)
				if(f[a[j]]!=i)ans++,f[a[j]]=i;//标记已输出颜色 
			printf("%d\n",ans);
		}
	}
	return 0;
}

