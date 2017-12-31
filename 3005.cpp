#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int n,a[11]={0},f[105]={0};
int main()
{
	for(int i=1;i<=10;i++)a[i]=getint();
	n=getint();
	for(int i=1;i<=100;i++)f[i]=0x7fffffff/2;
	f[0]=0;
	for(int i=1;i<=10;i++)
	for(int j=i;j<=n;j++)
		f[j]=min(f[j],f[j-i]+a[i]);
    printf("%d",f[n]);
	return 0;
}