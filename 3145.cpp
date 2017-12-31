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
int n,k,p,ans;
int col[200005],cost[200005],cnt[200005][55],last[200005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),k=getint(),p=getint();
	for(ri i=1;i<=n;i++)
		col[i]=getint(),cost[i]=getint();
	for(ri i=1;i<=n;i++)
	{
		for(ri j=0;j<k;j++)cnt[i][j]=cnt[i-1][j]+(col[i]==j);
		last[i]=(cost[i]<=p)?i:last[i-1];
	}
	for(ri i=1;i<=n;i++)
	{
		if(!last[i])continue;
		if(last[i]!=i)ans+=cnt[last[i]][col[i]];
		else ans+=cnt[i][col[i]]-1;
	}
	printf("%d",ans);
	return 0;
}

