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
#define lowbit(a) a&(-a)
using namespace std;
const int MAXN=25;
const int INF=0x7fffffff/2;
int n,l,len[MAXN],movie[MAXN][1005],m[25];
int f[(1<<20)+5],Ans=INF;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Binary(int T,int id)
{
	int l=0,r=m[id];
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(movie[id][mid]<=T)l=mid+1;
		else r=mid-1;
	}
	return r;	
}
int main()
{
	n=getint(),l=getint();
	for(ri i=1;i<=n;i++)
	{
		len[i]=getint(),m[i]=getint();
		for(ri j=1;j<=m[i];j++)
			movie[i][j]=getint();	
	}
	memset(f,-1,sizeof(f)),f[0]=0;
	for(int S=0;S<(1<<n);S++)
	{
		if(f[S]==-1)continue;
		if(f[S]>=l)
		{
			int cnt=0;
			for(int i=S;i>0;i-=lowbit(i))cnt++;
			Ans=min(Ans,cnt);
			continue;
		}
		for(ri j=1;j<=n;j++)
		{
			if(!(S&(1<<(j-1))))
			{
				int Far=Binary(f[S],j);
				if(!Far)continue;
				f[S|(1<<(j-1))]=max(f[S|(1<<(j-1))],movie[j][Far]+len[j]);
			}
		} 
	} 
	printf("%d\n",Ans==INF?-1:Ans);
	return 0;
}