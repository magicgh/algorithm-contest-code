#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n;
double a[105][105],s[105][105];
inline int GetInt()	
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Gauss(int x)
{
	double Max=abs(a[x][x]);
	int Maxno=x;
	for(int i=x+1;i<=n;i++)
		if(Max<abs(a[i][x]))Max=abs(a[i][x]),Maxno=i;//寻找最大主元
	if(x!=Maxno)
		for(int i=x;i<=n+1;i++)swap(a[x][i],a[Maxno][i]);//交换 
	for(int i=x+1;i<=n;i++)
	{
		double t=a[i][x]/a[x][x];//作商求倍数
		for(int j=x;j<=n+1;j++)a[i][j]-=a[x][j]*t;//加减消元 
	 } 
}
void init()
{
	n=GetInt();
	for(int i=1;i<=n+1;i++)
	for(int j=1;j<=n;j++)scanf("%lf",&s[i][j]);
	for(int i=2;i<=n+1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i-1][j]=(s[1][j]-s[i][j])*2;
			a[i-1][n+1]+=-(s[i][j]*s[i][j])+(s[1][j]*s[1][j]);
		}
	}
	for(int i=1;i<=n;i++)Gauss(i);
}
void output()
{
	double ans[105];
	for(int i=n;i>0;i--)
	{
		for(int j=n;j>i;j--)//回代 
			 a[i][n+1]-=a[i][j]*ans[j];
			 ans[i]=a[i][n+1]/a[i][i];
		}
		for(int i=1;i<=n;i++)printf("%.3lf ",ans[i]);
}
int main(){
	init();
	output();
	return 0;
}