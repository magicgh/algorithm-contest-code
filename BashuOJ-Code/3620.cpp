/*
等价于在ax+by=c中，已知a,b,c，求(x,y)，(x,y)即为两砝码(a,b)的个数
并要求使砝码总数(|x|+|y|)最小，在总数相同时，砝码总质量(a|x|+b|y|)最小 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define LL long long
using namespace std;
inline LL abs(LL x)
{
	if(x<0)return -x;
	else return x;
}
inline LL GetInt()
{
	LL num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(b==0)d=a,x=1,y=0;
	else
	{
		Exgcd(b,a%b,d,x,y);
		LL t=x;x=y;y=t-a/b*y;
	}
    return;
}
int main(){
	/*
	先用ExtraGcd得出ax+by=gcd(a,b)=d的特解(x0,y0)
	再把x0,y0，同时放大(c/d)倍
	求出通解x=x0+b/d*t,y=y0-a/d*t (t为整数) 
	*/		
	/*
	对于多解求总质量最小时
	令f(t)=|x0+b/d*t|+|y0-a/d*t|
	数形结合可知当|y0-a/d*t|=0，有f(t)min
	又因为t为整数
	所以t=y0/a*d
	*/ 
	LL x0,y0,d,a,b,c;
	while(a=GetInt(),b=GetInt(),c=GetInt())
	{
		if(a==0&&b==0&c==0)break;
		Exgcd(a,b,d,x0,y0);//扩展欧几里得 
		a/=d,b/=d,c/=d;//f(t)=|x0+b/d*t|+|y0-a/d*t|
		x0*=c,y0*=c;//扩大c倍，求解ax+by=c
		//以下的(x0-b),(y0+a)表示(b/d*t),(a/d*t)
		while(abs(x0)+abs(y0)>abs(x0-b)+abs(y0+a))x0-=b,y0+=a;
		while(abs(x0)+abs(y0)>abs(x0+b)+abs(y0-a))x0+=b,y0-=a;
		/*使abs(x0)+abs(y0)<=abs(x0-b)+abs(y0+a)
		    abs(x0)+abs(y0)<=abs(x0+b)+abs(y0-a)
		*/
		while((abs(x0)+abs(y0)==abs(x0-b)+abs(y0+a))&&(abs(a*x0)+abs(b*y0)>abs((x0-b))*a+abs((y0+a)*b)))x0-=b,y0+=a;
		while((abs(x0)+abs(y0)==abs(x0+b)+abs(y0-a))&&(abs(a*x0)+abs(b*y0)>abs((x0+b)*a)+abs((y0-a)*b)))x0+=b,y0-=a;
		//满足方程ax+by=c成立 
		printf("%d %d\n",abs(x0),abs(y0));	
	}	
	return 0;
}
