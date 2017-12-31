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
int n,k,a[105],f[105][55],ans=0;
int main()
{
	n=getint(),k=getint()+3;
	if(k*2>n){printf("-1");return 0;}
	for(int i=1;i<=n;i++)a[i]=getint();
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=k;j++)f[i][j]=0x7fffffff/2;//前i只选j双
	for(int i=0;i<=n;i++)f[i][0]=0;//不选为0 
	for(int i=2;i<=n;i++)
	for(int j=1;j<=k;j++)f[i][j]=min(f[i-1][j],f[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
	printf("%d",f[n][k]);
	return 0;
}

