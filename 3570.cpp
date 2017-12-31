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
const int MAXN=200005;
int x,n,m,a[MAXN],p[MAXN][55];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void ST()
{
	for(ri i=1;i<=n;i++)p[i][0]=a[i];
	for(ri j=1;j<=(int)log2(n);j++)
		for(ri i=1;i+(1<<j)-1<=n;i++)
			p[i][j]=max(p[i][j-1],p[i+(1<<(j-1))][j-1]);
}
inline int RMQ(int l,int r)
{
	if(l>r)swap(l,r);
	int k=log2(r-l+1);
	return max(p[l][k],p[r-(1<<k)+1][k]);
}
int main()
{
	m=getint();
	while(~(x=getint()))a[++n]=x;
	ST();
	for(ri i=1;i<=n-m+1;i++)
		printf("%d\n",RMQ(i,m+i-1));
	return 0;
}

