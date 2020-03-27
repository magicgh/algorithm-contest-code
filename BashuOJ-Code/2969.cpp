#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n;
inline int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main(){
	scanf("%d",&n);
	int a,b,c,d;
	for(int i=1;i<=n;i++)
	{
		bool bj=0;
		scanf("%d/%d-%d/%d",&a,&b,&c,&d);
		int lcm=b*d/gcd(b,d);
		int ans1=(lcm/b)*a-(lcm/d)*c;
		if(ans1<0)printf("-");
		ans1=abs(ans1);
		int gcd1=gcd(lcm,ans1);
		int a1=ans1/gcd1,a2=lcm/gcd1;
		if(a1%a2==0)printf("%d\n",a1/a2);
		else printf("%d/%d\n",ans1/gcd1,lcm/gcd1);
	}
	return 0;
}
