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
const int MAXN=5000005;
int n,m,s[MAXN],a[MAXN],b[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Solve()
{
	int cnt=0,Ans=0,pos=0,tot=0;
	for(ri i=1;i<=n;i++)
		s[i]=s[i-1]+(a[i]?1:-1),cnt=(!s[i])?cnt+1:cnt;
	Ans=(cnt>=m&&s[n]==0)?0:(abs(abs(s[n])-1)/m+1);//计算个数差的最大值	 
	for(ri i=1;i<=n;i++)
	{
		if(tot==m-1){b[++tot]=n-i+1;break;}//分最后一块
		if(abs(s[n]-s[i])<=Ans*(m-tot-1))
		{
			b[++tot]=i-pos;
			pos=i;
		} 
	}
}
int main()
{
	char ch;
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		while(ch=getchar())if(ch=='0'||ch=='1')break;
		a[i]=ch-'0';
	}
	Solve();
	for(ri i=1;i<=m;i++)printf("%d ",b[i]);
	printf("\n");
	for(ri i=1;i<=(n>>1);i++)swap(a[i],a[n-i+1]);
	Solve();
	for(ri i=m;i>=1;i--)printf("%d ",b[i]);
	return 0;
}

