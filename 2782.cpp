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
const int MAXN=20005;
int k,n,a[MAXN],s[MAXN],sa[MAXN],Rank[MAXN],tmp[MAXN],h[MAXN];
inline bool cmp(const int &i,const int &j)
{
	if(Rank[i]!=Rank[j])return Rank[i]<Rank[j];
	return (i+k<=n?Rank[i+k]:-1)<(j+k<=n?Rank[j+k]:-1);
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DA()
{
	for(ri i=1;i<=n;i++)sa[i]=i,Rank[i]=a[i];
	for(k=1;k<=n;k*=2)
	{
		sort(sa+1,sa+n+1,cmp);
		tmp[sa[1]]=1;	
		for(ri i=2;i<=n;i++)
			tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);//若rank[sa[i-1]]比rank[sa[i]]小,更新排名 
		for(ri i=1;i<=n;i++)Rank[i]=tmp[i];
	}
}
void LCP()
{
	int k=0;h[1]=0;
	for(ri i=1;i<=n;i++)
	{
		if(Rank[i]==1)continue;
		ri j=sa[Rank[i]-1];
		while(a[i+k]==a[j+k])k++;
		h[Rank[i]]=k;
		k=k?k-1:k;
	}
}
inline bool Check(int x)
{
	int Min=sa[1],Max=sa[1];
	for(ri i=2;i<=n;i++)
	{
		if(h[i]>=x)
		{
			Max=max(Max,sa[i]);
			Min=min(Min,sa[i]);
			if(Max-Min>=x)return 1;
		}
		else Max=Min=sa[i];
	}
	return 0;
}
void Binary()
{
	int l=0,r=n/2;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))l=mid+1;
		else r=mid-1;
	}	
	if(l<5)printf("0");\
	else if(l*2>n)printf("%d",l-1);
	else printf("%d",l);
}
int main()
{		
	n=getint();
	for(ri i=1;i<=n;i++)s[i]=getint();
	for(ri i=1;i<=n;i++)a[i]=s[i]-s[i-1]+100;
	DA(),LCP(),Binary();
	return 0;
}