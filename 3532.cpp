#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define ll long long
using namespace std;
inline void Exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	if(b==0)x=1,y=0,d=a;
	else
	{
		Exgcd(b,a%b,d,x,y);
		int t=x;x=y;y=t-a/b*y;
	}
}
int main(){
	ll a,b,d,x,y;
	scanf("%lld%lld",&a,&b);
	Exgcd(a,b,d,x,y);
	printf("%lld",(x/d%(b/d)+(b/d))%(b/d));
	return 0;
}
	