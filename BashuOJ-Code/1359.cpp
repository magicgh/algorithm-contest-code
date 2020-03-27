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
char ch[MAXN];
int k,n,a[MAXN],sa[MAXN],Rank[MAXN],tmp[MAXN],h[MAXN];
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
	int k=0;h[1]=0;//预处理 
	for(ri i=1;i<=n;i++)
	{
		if(Rank[i]==1)continue;
		ri j=sa[Rank[i]-1];//取前一名位置
		while(a[i+k]==a[j+k])k++;//获得公共前缀长度
		h[Rank[i]]=k;
		k=k?k-1:k;//h[i]>=h[i-1]-1,前一串的第一个公共字符,后一串不可能拥有 
	}
}
int main()
{	
	scanf("%s",ch+1);	
	n=strlen(ch+1);
	for(ri i=1;i<=n;i++)a[i]=int(ch[i]-96);
	DA(),LCP();
	for(ri i=1;i<=n;i++)printf("%d ",sa[i]);
	printf("\n");
	for(ri i=1;i<=n;i++)printf("%d ",h[i]);
	return 0;
}

