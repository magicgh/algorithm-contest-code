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
int k,n,mid,len,a[MAXN],sa[MAXN],Rank[MAXN];
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
	int *tmp=new int[MAXN];
	for(ri i=1;i<=n;i++)sa[i]=i,Rank[i]=a[i];
	for(k=1;k<=n;k*=2)
	{
		sort(sa+1,sa+n+1,cmp);
		tmp[sa[1]]=1;	
		for(ri i=2;i<=n;i++)
			tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);
		for(ri i=1;i<=n;i++)Rank[i]=tmp[i];
	}
	delete []tmp;
}
void LCP()
{
	int *h=new int[MAXN];
	int p=0;h[1]=0;
	for(ri i=1;i<=n;i++)
	{
		if(Rank[i]==1)continue;
		ri j=sa[Rank[i]-1];
		while(a[i+p]==a[j+p])p++;
		h[Rank[i]]=p;
		p=p?p-1:p;
	}
	int ans=0;
	for(ri i=1;i<=n;i++)
		if(ans<h[i]&&((sa[i]<=mid&&sa[i-1]>mid)||(sa[i]>mid&&sa[i-1]<=mid)))ans=h[i];
		printf("%d",ans);
}
int main()
{	
	char *ch=new char[100005];
	scanf("%s",ch+1);
	len=strlen(ch+1);
	for(ri i=1;i<=len;i++)a[i]=int(ch[i]-96);
	a[n=len+1]=144,mid=len;
	scanf("%s",ch+1);
	len=strlen(ch+1);
	for(ri i=1;i<=len;i++)a[++n]=int(ch[i]-96);
	delete []ch;
	DA(),LCP();
	return 0;
}
