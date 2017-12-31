#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int INF=0x7fffffff;
char ch[1005];
int n,m,b[1005],w[1005],f[65][1005];
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
	scanf("%s",ch);
	for(ri i=0;i<n;i++)
	{
		w[i+1]=w[i],b[i+1]=b[i];
		if(ch[i]=='0')w[i+1]+=1;
		if(ch[i]=='1')b[i+1]+=1;
	}
	for(ri i=1;i<=n;i++)f[1][i]=b[i]*w[i];//全部放在第一个马厩 
	for(ri i=2;i<=m;i++)//马厩数 
		for(ri j=i;j<=n;j++)//前j匹马 
		{
			f[i][j]=INF;
			for(ri k=i-1;k<=j-1;k++)
			f[i][j]=min(f[i][j],f[i-1][k]+(b[j]-b[k])*(w[j]-w[k]));
		}
	printf("%d",f[m][n]);	
	return 0;
}

