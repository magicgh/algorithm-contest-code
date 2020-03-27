#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a,b,c,x,y,z,T,sum;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	T=getint();
	while(T--)
	{
		a=getint(),b=getint(),c=getint(),x=getint(),y=getint(),z=getint();
		if(a<x&&b<y&&c<z){printf("NO\n");continue;}
		sum=(((a-x)>0)?((a-x)/2):0)+(((b-y)>0)?((b-y)/2):0)+(((c-z)>0)?((c-z)/2):0);
		if(a<x)
		{
			sum-=(x-a);
			if(sum<0){printf("NO\n");continue;}
		}
		if(b<y)
		{
			sum-=(y-b);
			if(sum<0){printf("NO\n");continue;}
		}
		if(c<z)
		{
			sum-=(z-c);
			if(sum<0){printf("NO\n");continue;}
		}
		printf("YES\n");
	}
	return 0;
}