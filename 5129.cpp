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
const int MAXN=405;
int n,m,a[MAXN][MAXN];
ll k,Ans,s[MAXN][MAXN],Cnt[1000005],Num[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=GetInt(),m=GetInt(),k=GetLL();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)a[i][j]=GetInt();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)s[i][j]=(s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j]+k)%k;
	for(ri ax=0;ax<n;ax++)
			for(ri bx=ax+1;bx<=n;bx++)
			{
				Cnt[0]=1;
				for(ri y=1;y<=m;y++)
				{
					Num[y]=(s[bx][y]-s[ax][y]+k)%k;
					Ans+=Cnt[Num[y]];
					Cnt[Num[y]]++;
				}
				for(ri y=1;y<=m;y++)Cnt[Num[y]]=0;
			}
	printf("%lld\n",Ans);
	return 0;
}

