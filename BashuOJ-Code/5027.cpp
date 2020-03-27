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
ll n,m,alpha,beta,a1,a2;
ll List[200005];
bool Hash[100005];
inline const ll getll()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getll(),m=getll(),alpha=getll()%n,beta=getll()%n;
	List[1]=getll(),List[2]=getll();
	Hash[List[1]]=1;Hash[List[2]]=1;
	for(ri i=3;i<=m;i++)
	{
		if(i-n/2-1>0)Hash[List[i-n/2-1]]=0;
		ll pos=((alpha%n*List[i-1]%n)%n+((beta%n)*(List[i-2]%n)))%n;
		while(Hash[pos])pos=(pos+1)%n;
		List[i]=pos;Hash[pos]=1;
		printf("%lld ",List[i]);
	}
	return 0;
}