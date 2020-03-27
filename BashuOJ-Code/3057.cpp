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
int n,m,p;
vector<ll>a,b,c;
int main()
{
	ll x,Ans=0;
	scanf("%d%d",&n,&m);
	for(ri i=0;i<n;i++)
	{
		scanf("%lld",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(ri i=0;i<n;i++)
	{
		scanf("%lld",&x);
		b.push_back(x);
	}
	sort(b.begin(),b.end());
	for(p=0;p<n/2;p++)
	{
		c.push_back(abs(a[p]-b[n-p-1]));
		c.push_back(abs(a[n-p-1]-b[p]));
	}
	if(n&1)c.push_back(abs(a[p]-b[p]));
	sort(c.begin(),c.end(),greater<ll>());
	for(ri i=0;i<m;i++)Ans+=c[i];
	printf("%lld",Ans);
	return 0;
}

