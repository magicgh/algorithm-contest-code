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
//x,y,d取地址作为当时的方程的解(函数调用停止后即为最终的解)，a,b则作为方程的系数
{
	/*(n-m)T+LP=X-Y*/
	if(b==0)x=1,y=0,d=a;//若 b=0, 则最大公约数为 a,a=1*a+0*0
	else 
	{
		ExtraGcd(b,a%b,d,x,y);
		int t=x;//t为y=x'-(a/b)*y'中的x'
		x=y;y=t-a/b*y;
		/*
		由d=gcd(a,b)=gcd(b,a%b)可得d=bx'+(a%b)y'
        ->d'=bx'+(a%b)y'=bx'+(a-(a/b)*b)y'=ay'+b(x'-(a/b)*y')
        又因为d=ax+by，则有两个等式：x=y'; y=x'-(a/b)*y'
       */ 
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
	if(n<m)swap(x,y),swap(m,n);//n-m<0,交换(x,y),(m,n)的值 
	ExtraGcd(n-m,l,d,a,b);//扩展欧几里得函数求解
	if(m==n||(x-y)%d!=0)//若(X-Y)%d!=0 或者 m=n 则无解
		puts("Impossible");
	else 
	{
	printf("%lld\n",(a*(x-y)/d%(l/d)+(l/d))%(l/d));
    }
	//最小正整数解 x=(x0%(b/d)+b/d)%(b/d)
	/*此式相当于x=x0+k*(b/d)中已知x求x0的一个过程
	由上式可知x0=x-k*(b/d)
	则x0%(b/d)就可以代换为(x-k*(b/d))%(b/d)=x%(b/d)
	又因为x和(b/d)互质
	所以x%(b/d)=x
	因为x可能为负数
	所以应再加上(b/d)并整体取余(b%d)
	即为x=(x0%(b/d)+b/d)%(b/d)
	*/
	return 0;
}
