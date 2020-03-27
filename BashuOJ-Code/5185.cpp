#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=100005;
const int MAXM=55;
int Color[MAXN];
bool Hash[MAXM];
int n,m;
ll cnt;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=GetInt(),m=GetInt();
	for(ri i=1;i<=m;i++)
	{
		int l=GetInt(),r=GetInt();
		for(ri j=l;j<=r;j++)Color[j]=i;
	}
	for(ri i=1;i<=n;i++)Hash[Color[i]]=1;
	for(ri i=1;i<=m;i++)if(Hash[i])cnt++;
	printf("%lld\n",(1ll<<cnt));
	return 0;
}
