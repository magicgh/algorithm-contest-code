#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long N,Multi=1,Ans=0;
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
		long long t=x;x=y;y=t-a/b*y;
	}
	return;
}
int main(){
	long long a[11],b[11],m[11],x,y,d; 
	N=GetInt();
	for(int i=1;i<=N;i++)
	{
		a[i]=GetInt();
		b[i]=GetInt();
		Multi*=a[i];
	}
	for(int i=1;i<=N;i++)
	{
	m[i]=Multi/a[i];
	ExtraGcd(m[i],a[i],d,x,y);
	Ans=((Ans+m[i]*x*b[i])%Multi+Multi)%Multi;
	}
	printf("%lld",Ans);
	return 0;
}
