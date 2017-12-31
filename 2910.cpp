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
int map[1005][2005],orbit[2005][2005];
int n,m,k,p;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int x,int r)
{
	int now=1,next,ans=1;
	while(true)
	{
		if(now+2*r>=2*n)break;
		for(next=min(2*n,now+2*r+1);next>now;next--)
			if(orbit[x][next])break;
		if(next<=now)return 0;
		now=next,ans++;
	}
	return (ans<=k);
}
inline int Binary(int x)
{
	int l=0,r=n/2;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(x,mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	char ch;
	n=getint(),m=getint(),k=getint(),p=m*2;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=p;j++)
		{
			while(ch=getchar())if(ch=='0'||ch=='1')break;
			map[i][j]=ch-'0';
		}
	for(ri i=1;i<=m;i++)
	{
		int cnt=0;
		for(ri j=n/2+1;j<=n;j++)orbit[i][++cnt]=map[j][i];
		for(ri j=n;j>=1;j--)orbit[i][++cnt]=map[j][i+m];
		for(ri j=1;j<=n/2;j++)orbit[i][++cnt]=map[j][i];
	}
	for(ri i=1;i<=m;i++)
		printf("%d\n",Binary(i));
	return 0;
}