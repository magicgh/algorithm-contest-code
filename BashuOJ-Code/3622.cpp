#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int isprime[1000005]={0,1,1};
long long ans=0;
inline bool Prime(long long x)
{
	if(x<=1000000&&isprime[x]!=0)//小范围的备忘优化 
	{
		if(isprime[x]==1)return true; 
		if(isprime[x]==-1)return false;
	}
	else
	{
		for(int i=2;i<=sqrt(x);i++)
			if(x%i==0)
			{
			if(x<=1000000)isprime[x]=-1;
			return false;
		    }
		if(x<=1000000)isprime[x]=1;
		return true;
	}
}
inline long long quickmi(long long a,long long b,long long MOD)//a^b%MOD
{
	ans=1;
	while(b)
	{
		if(b&1)ans=(ans*a)%MOD;
		b>>=1;
		a=(a*a)%MOD;
	}
	return ans;
} 
int main(){
	long long a,p;
	while(scanf("%lld%lld",&p,&a)!=EOF)
	{
		if(p==0&&a==0)break;
		if(Prime(p))
		{
		puts("no");
		continue;
	}
		else 
		{
			ans=1;
			ans=quickmi(a,p,p);
			if(ans==(a%p))printf("yes\n");
			else printf("no\n");
		}
	}	
	return 0;
}
