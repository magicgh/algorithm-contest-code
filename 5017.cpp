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
const int INF=0x7fffffff/2;
int n,m,a[105],Ave,sum;
int f[3][20][217][3005],Bin[105][217][3005];
double Ans=-1e20;	
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DP()
{
	for(ri j=0;j<=m;j++)
		for(ri k=0;k<=212;k++)
			for(ri w=0;w<=3000;w++)f[0][j][k][w]=f[1][j][k][w]=-INF;//初始化 
	int now=0,next=1;
	f[0][0][0][0]=0;
	for(ri i=0;i<n;i++)
	{
		//Bin[i][j][k]:前i个数中选j个和为k的最大平方和 
		if(i>0)for(ri j=0;j<=m;j++)
				for(ri k=0;k<=212;k++)
					for(ri w=0;w<=Bin[i-1][j][k];w++)f[next][j][k][w]=-INF;
		for(ri j=0;j<=i&&j<=m;j++)
			for(ri k=0;k<=212;k++)
				for(ri w=0;w<=Bin[i][j][k];w++)
				 	if(f[now][j][k][w]!=-INF)
				 	{
				 		f[next][j][k][w]=max(f[next][j][k][w],f[now][j][k][w]);
						Bin[i+1][j][k]=max(Bin[i+1][j][k],w);
						if(j<m)//还可以选 
						{
							f[next][j+1][k+a[i+1]][w+a[i+1]*a[i+1]]=max(f[next][j+1][k+a[i+1]][w+a[i+1]*a[i+1]],f[now][j][k][w]+(j+1-Ave)*a[i+1]);
							Bin[i+1][j+1][k+a[i+1]]=max(Bin[i+1][j+1][k+a[i+1]],w+a[i+1]*a[i+1]);
						} 
					}
		now=next,next^=1;
	}
	for(int k=0;k<=212;k++)
		for(int w=0;w<=Bin[n][m][k];w++)
			if(f[now][m][k][w]!=-INF)
				Ans=max(Ans,f[now][m][k][w]/sqrt(sum)/sqrt(w-(double)(k*k)/m));
}
int main()
{
	n=getint(),m=getint(),Ave=(m+1)>>1;
	for(ri i=1;i<=n;i++)
	{
		a[i]=getint();
		if(i<=m)sum+=(i-Ave)*(i-Ave);
	}
	DP();
	printf("%.4lf\n",Ans);
	return 0;
}
