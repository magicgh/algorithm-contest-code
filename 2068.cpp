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
int k,len,slen,n,sa[400005],Rank[400005],a[400005],tmp[400005],h[400005],f[400005][19],g[400005];
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
	for(ri j=1;j<=int(log2(n));j++)
		for(ri i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
inline int RMQ(int l,int r)
{
	if(Rank[l]>Rank[r])swap(l,r);
	if(l==r)return slen-l+1;
	l=Rank[l]+1;r=Rank[r];
	int x=(int)log2(r-l+1);
	return min(f[l][x],f[r-(1<<x)+1][x]);
}
int main()	
{
	
	while(~(ch[++len]=getchar()));
	for(ri i=1;i<=len;i++)
		if(isalpha(ch[i]))a[++n]=(int)toupper(ch[i]),g[n]=i;
	slen=n,a[++n]=int('&'),g[n]=len+1;
	for(ri i=1;i<=len;i++)
		if(isalpha(ch[len-i+1]))a[++n]=(int)toupper(ch[len-i+1]),g[n]=len+1+i;
	DA(),LCP(),ST();
	int p=0,ans=0,pos=0x7fffffff;
	for(ri i=1;i<=slen;i++)
	{
		p=RMQ(i,n-i+1);
		if((p<<1)>ans)ans=(p<<1),pos=i-p+1;
		else if((p<<1)==ans)pos=min(pos,i-p+1);
		p=RMQ(i,n-i);
		if((p<<1)-1>ans)ans=(p<<1)-1,pos=i-p+2;
		else if((p<<1)-1==ans)pos=min(pos,i-p+2);
	}
	printf("%d\n",ans-1);
	for(ri i=g[pos];i<=g[pos+ans-2];i++)printf("%c",ch[i]);
	return 0;
}