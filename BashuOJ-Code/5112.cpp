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
const int MAXN=20005;
const int MAXK=105;
int N,K;
ll Max,f[MAXK][MAXN],x[MAXN],y[MAXN],sum[MAXN],q[MAXN];
inline double Slope(int Now,int i,int j)
{
	return (double)(f[Now-1][i]-f[Now-1][j])/(double)(i-j);
}
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void ST1()
{
	for(ri i=1;i<=K;i++)
		for(ri j=1;j<=N;j++)
			for(ri k=0;k<j;k++)
				f[i][j]=max(f[i][j],f[i-1][k]+sum[j]*(j-k));
	for(ri i=K;i<=N;i++)
		Max=max(Max,f[K][i]);
	printf("%lld\n",Max);
}
void DP()
{
	for(ri i=1;i<=K;i++)
	{
		int head=0,tail=0;q[0]=0;
		for(ri j=1;j<=N;j++)
		{
			while(head<tail&&Slope(i,q[head],q[head+1])>=(double)sum[j])head++;
			while(head<tail&&Slope(i,q[tail-1],q[tail])<=Slope(i,q[tail],j))tail--;
			f[i][j]=max(f[i][j],f[i-1][q[head]]+sum[j]*(j-q[head]));
			q[++tail]=j;
		}
	}
	for(ri i=K;i<=N;i++)
		Max=max(Max,f[K][i]);
	printf("%lld\n",Max);
}
int main()
{
	N=GetInt(),K=GetInt();
	for(ri i=1;i<=N;i++)
		x[i]=GetInt(),y[i]=GetInt(),sum[i]=y[i]-x[i]+1;
 	DP();
	return 0;
}


