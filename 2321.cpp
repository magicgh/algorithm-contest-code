#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int n;
double a[105],f1[105],f2[105];
int main()
{
	n=getint();
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
	f1[0]=100;
	for(int i=1;i<=n;i++)
	{
		f1[i]=max(f1[i-1],f2[i-1]/a[i]*100);
		f2[i]=max(f2[i-1],f1[i-1]/100*a[i]);
	}
	printf("%.2lf",f1[n]);
	return 0;
}

