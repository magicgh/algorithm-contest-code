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
int n,m,rev,w[2005],f[2005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void CDQ(int l,int r)
//利用分治思想,对(l,mid)与(mid+1,r)进行背包,用右区间更新左区间的值,巧妙的排除了mid,在l=r时即是一种情况 
{
	int g[2005];
	if(l==r)
	{
		for(ri i=1;i<=m;i++)printf("%d",f[i]);
		printf("\n");return;
	}
	int mid=(l+r)>>1;
	for(ri i=0;i<=m;i++)g[i]=f[i];//备份
	for(ri i=mid+1;i<=r;i++)
		for(ri j=m;j>=w[i];j--)f[j]=(f[j]+f[j-w[i]])%10;
	CDQ(l,mid);
	for(ri i=0;i<=m;i++)f[i]=g[i];//复原
	for(ri i=l;i<=mid;i++)
		for(ri j=m;j>=w[i];j--)f[j]=(f[j]+f[j-w[i]])%10;
	CDQ(mid+1,r);
}
int main()
{
	n=getint(),m=getint(),f[0]=1;
	for(ri i=1;i<=n;i++)w[i]=getint();
	CDQ(1,n); 
	return 0;
}

