#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
long long l,n,m,dist[50005];
inline bool Check(int x)
{
	int sum=0,k=0;
	for(int i=1;i<=n;i++)
    {
    	if(dist[i]-sum<x)k++;
    	else sum=dist[i];
	}
	if(k<=m)return 1;
	else return 0;
}
inline long long binary(long long l,long long r)
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(Check(mid))l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main()
{
	long long Min=0x7fffffff;
	memset(dist,0,sizeof(dist));
	scanf("%lld%lld%lld",&l,&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&dist[i]);
	dist[++n]=l;
	printf("%lld",binary(0,l));
return 0;
}