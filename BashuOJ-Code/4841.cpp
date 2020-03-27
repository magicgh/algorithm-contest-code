#include<iostream>
using namespace std;
long long n,a=1,b=1,base=0;
inline long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
int main()
{
	scanf("%lld",&n);
	for(register int i=2;i<=n;++i)a=a*i+b,b*=i,base=gcd(a,b),a/=base,b/=base;
	a*=n,printf("%lld",a/b);	
	if(a%b!=0)a=a-(a/b)*b,base=gcd(a,b),printf("(%lld/%lld)",a/base,b/base);
	return 0;
}