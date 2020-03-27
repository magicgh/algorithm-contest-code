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
using namespace std;
const int MAXN=200005; 
int n,k,q,a[MAXN],sa[MAXN],tmp[MAXN],Rank[MAXN],h[MAXN],f[MAXN][19];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const int &i,const int &j)
{
	if(Rank[i]!=Rank[j])return Rank[i]<Rank[j];
	return (i+k<=n?Rank[i+k]:-1)<(j+k<=n?Rank[j+k]:-1);
}
void DA()
{
	for(ri i=1;i<=n;i++)sa[i]=i,Rank[i]=a[i];
	for(k=1;k<=n;k<<=1)
	{
		sort(sa+1,sa+n+1,cmp);
		tmp[sa[1]]=1;
		for(ri i=2;i<=n;i++)
			tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);
		for(ri i=1;i<=n;i++)Rank[i]=tmp[i];
	}
}
void LCP()
{
	int p=0;
	for(ri i=1;i<=n;i++)
	{
		if(Rank[i]==1)h[Rank[i]]=0;
		ri j=sa[Rank[i]-1];
		while(a[i+p]==a[j+p])p++;
		h[Rank[i]]=p;
		p=p?p-1:p;
	}
}
void ST()
{
	for(ri i=1;i<=n;i++)f[i][0]=h[i];
	for(ri j=1;(1<<j)<=n;j++)
		for(ri i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
inline int RMQ(int l,int r)
{
	int x=(int)log2(r-l+1);
	return min(f[l][x],f[r-(1<<x)+1][x]);
}
int main()
{
	n=getint(),q=getint();
	for(ri i=1;i<=n;i++)a[i]=getint();
	DA(),LCP(),ST();
	for(ri i=1;i<=q;i++)
	{
		int x=getint(),y=getint();
		if(x==y)printf("%d\n",n-x+1);
		else
		{
			if(Rank[x]>Rank[y])swap(x,y);
			printf("%d\n",RMQ(Rank[x]+1,Rank[y]));
		}
	}
	return 0;
}