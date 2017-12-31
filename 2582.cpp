#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
char s[505];
int n,m,Max,f[505][105][105];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		char ch;
		while(ch=getchar())
			if(isalpha(ch))break;
		s[i]=ch;
	}
	memset(f,-0x3f,sizeof(f));
	f[1][0][0]=f[0][0][0]=0;
	if(s[1]=='j')f[1][1][0]=0;
	else f[1][0][1]=0;
	for(ri i=2;i<=n;i++)
		for(ri j=0;j<=m;j++)
			for(ri k=0;k<=m;k++)
			{
				f[i][j][k]=f[i-1][j][k];
				if(s[i-1]=='j'&&s[i]=='z')f[i][j][k]=max(f[i][j][k],f[i-2][j][k]+1);
				if(s[i-1]=='j'&&s[i]=='j'&&j)f[i][j][k]=max(f[i][j][k],f[i-2][j-1][k]+1);
				if(s[i-1]=='z'&&s[i]=='z'&&k)f[i][j][k]=max(f[i][j][k],f[i-2][j][k-1]+1);
				if(s[i-1]=='z'&&s[i]=='j'&&j&&k)f[i][j][k]=max(f[i][j][k],f[i-2][j-1][k-1]+1);
				if(j==k)Max=max(Max,f[i][j][k]);
			}
	printf("%d\n",Max);
	return 0;
}

