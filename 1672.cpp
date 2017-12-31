#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
inline long long GetInt()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void ExtraGcd(long long a,long long b,long long &d,long long &x,long long &y)
{
	if(b==0)x=1,y=0,d=a;
	else 
	{
		ExtraGcd(b,a%b,d,x,y);
		int t=x;
		x=y;y=t-a/b*y;
	}
	return;
}
long long x,y,m,n,l;
int main(){
	long long a,b,d;
	x=GetInt();
	y=GetInt();
	m=GetInt();
	n=GetInt();
	l=GetInt();
	if(n<m)swap(x,y),swap(m,n);
	ExtraGcd(n-m,l,d,a,b);
	if(m==n||(x-y)%d!=0)
		puts("Impossible");
	else 
	{
	printf("%lld\n",(a*(x-y)/d%(l/d)+(l/d))%(l/d));
    }

	return 0;
}
