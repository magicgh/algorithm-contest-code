#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int n;
long long f,f1=8,f2=2;
int main()
{
	n=GetInt();
	if(n%2==1)printf("0\n");
	else
	{
		n=n/2-1;
		if(n==1)printf("2\n");
		else if(n==2)printf("8\n");
		else
		{
		for(int i=3;i<=n;i++)
		{
		f=((4*f1)%1000-(2*f2)%1000+1000)%1000;
		f2=f1%1000;
		f1=f%1000;
		}
			printf("%d\n",f);
		}
	}
 return 0;
}