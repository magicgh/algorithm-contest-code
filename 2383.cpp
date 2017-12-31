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
int n,m,s[405][405],Ans;
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
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			char ch;
			while(ch=getchar())if(ch=='0'||ch=='1')break;
			if(ch=='0')s[i][j]=s[i-1][j]-1;
			else s[i][j]=s[i-1][j]+1;
		}
	for(ri i=1;i<n;i++)
		for(ri j=i;j<=n;j++)
		{
			int t=s[j][1]-s[i-1][1];
			for(ri k=2;k<=m;k++)
			{
				t=max(t,0)+s[j][k]-s[i-1][k];
				Ans=max(t,Ans);
			}
		}
		printf("%d",Ans);
	return 0;
}

