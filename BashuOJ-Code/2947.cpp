#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long gcd(long long a,long long b)
{
	return (b==0)?a:gcd(b,a%b);
}
int main(){
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	int t=gcd((b-a)*(b-a)-(b-c-a)*(b-c-a),(b-a)*(b-a));
	if((b-a)*(b-a)-(b-c-a)*(b-c-a)==0)printf("0");
	else printf("%lld/%lld",((b-a)*(b-a)-(b-c-a)*(b-c-a))/t,(b-a)*(b-a)/t);
	return 0;
}
