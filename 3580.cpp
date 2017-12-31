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
char ch[200005];
int n,k,a[200005],sa[200005],h[200005],tmp[200005],Rank[200005];
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
	for(k=1;k<=n;k*=2)
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
	int p=0;h[1]=0;
	for(ri i=1;i<=n;i++)
	{
		if(Rank[i]==1)continue;
		ri j=sa[Rank[i]-1];
		while(a[i+p]==a[j+p])p++;
		h[Rank[i]]=p;
		p=p?p-1:p;
	}
 } 
int main()
{	
	gets(ch+1);
	n=strlen(ch+1);
	for(ri i=1;i<=n;i++)a[i]=(int)ch[i];
	DA(),LCP();
	long long ans=0;
	for(ri i=1;i<=n;i++)ans+=(long long)((n-sa[i]+1)-h[i]);
	printf("%lld",ans);
	return 0;
}