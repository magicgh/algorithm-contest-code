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
const int MAXN=50005;
ll n,a[MAXN],ave,Ans,sum;
inline const int GetInt()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)
		a[i]=GetInt(),ave+=a[i];
	ave/=n;
	for(ri i=1;i<=n;i++)
		sum+=a[i]-ave,Ans+=(sum>=0?sum:-sum);
	printf("%lld\n",Ans);
	return 0;
}