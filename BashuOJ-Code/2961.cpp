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
int ans,n,map[1005][1005],f[1005][1005];	
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
	char ch;
	n=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			while(ch=getchar())if(ch=='0'||ch=='1')break;
			map[i][j]=ch-'0';
		}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			if(!map[i][j]){f[i][j]=0;continue;}
			int tmp=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]));
			f[i][j]=tmp+1;
			ans=max(f[i][j],ans);
		}
	printf("%d",ans*ans);
	return 0;
}

