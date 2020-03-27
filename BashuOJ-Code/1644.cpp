#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
const int MAXN=105;
int map[MAXN][MAXN],f[MAXN][MAXN],d[5]={-2,-1,0,1,2};
int w,h,t,p1,p2,v,s,totalt=0,maxs;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	w=getint();h=getint()-1;
	while(~scanf("%d%d%d%d",&t,&p2,&v,&s))
	{
		if(h%v)continue;
		p1=t+h/v;map[p1][p2]+=s;totalt=max(totalt,p1);
	}
	for(int i=1;i<=w;i++)f[totalt][i]=map[totalt][i];
	for(int i=totalt-1;i>=0;i--)
		for(int j=1;j<=w;j++)
		{
			maxs=0;
			for(int k=0;k<=4;k++)	
				if(j+d[k]>=1&&j+d[k]<=w)maxs=max(maxs,f[i+1][j+d[k]]);
			f[i][j]=maxs+map[i][j];
		}
		printf("%d",f[0][w/2+1]);
	return 0;
}
