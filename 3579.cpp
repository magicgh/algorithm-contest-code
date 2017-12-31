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
char ch[400005];
int k,len,n,sa[400005],Rank[400005],a[400005],first[400005],second[400005],sum[400005],h[400005],f[400005][19];
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
void DA(int M)//强行卡sort   不爽   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   All of you are Hanzhong balls
{	
	int i,j,p,*x=Rank,*y=second;
	for(i=1;i<=M;i++)sum[i]=0;
	for(i=1;i<=n;i++)sum[x[i]=(int)a[i]]++;
	for(i=1;i<=M;i++)sum[i]+=sum[i-1];
	for(i=n;i>=1;i--)sa[sum[x[i]]--]=i;
	for(j=1,p=1;p<n;j<<=1,M=p)
	{
		for(i=n-j+1,p=0;i<=n;i++)y[++p]=i;
		for(i=1;i<=n;i++)if(sa[i]-j>0)y[++p]=sa[i]-j;
		for(i=1;i<=n;i++)first[i]=x[y[i]];
		for(i=1;i<=M;i++)sum[i]=0;
		for(i=1;i<=n;i++)sum[first[i]]++;
		for(i=1;i<=M;i++)sum[i]+=sum[i-1];
		for(i=n;i>=1;i--)sa[sum[first[i]]--]=y[i];
		swap(x,y);x[sa[1]]=1;
		for(i=2,p=1;i<=n;i++)
		{	
			if(y[sa[i]]!=y[sa[i-1]]||y[sa[i]+j]!=y[sa[i-1]+j])p++;
			x[sa[i]]=p;
		}
	}
	for(i=1;i<=n;i++)Rank[sa[i]]=i;
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
	for(ri j=1;j<=int(log2(n));j++)
		for(ri i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
inline int RMQ(int l,int r)
{
	if(Rank[l]>Rank[r])swap(l,r);
	if(l==r)return len-l+1;
	l=Rank[l]+1;r=Rank[r];
	int x=(int)log2(r-l+1);
	return min(f[l][x],f[r-(1<<x)+1][x]);
}
int main()	
{
	scanf("%s",ch+1);
	len=strlen(ch+1);
	for(ri i=1;i<=len;i++)a[i]=(int)ch[i];
	a[len+1]=int('&');
	for(ri i=1;i<=len;i++)a[i+len+1]=(int)ch[len-i+1];
	n=(len<<1)+1;
	DA(128),LCP(),ST();
	int p=0,ans=0,pos=0;
	for(ri i=1;i<=len;i++)
	{
		p=RMQ(i,n-i+1);
		if((p<<1)>ans)ans=(p<<1),pos=i-p+1;
		p=RMQ(i,n-i);
		if((p<<1)-1>ans)ans=(p<<1)-1,pos=i-p+2;
	}
	for(ri i=pos;i<=pos+ans-2;i++)printf("%c",ch[i]);
	return 0;
}