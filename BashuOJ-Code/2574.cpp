#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n;
double a[105][105];
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
		if(a[x][x]!=0)//分母不为0
		{ 
		double t=a[i][x]/a[x][x];//作商求倍数
		for(int j=x;j<=n+1;j++)a[i][j]-=a[x][j]*t;//加减消元 
		} 
	 } 
}
void init()
{
	n=GetInt();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n+1;j++)//读入增广矩阵
	a[i][j]=GetInt();
	for(int i=1;i<=n;i++)Gauss(i);
}
void output()
{
	double ans[105];
	for(int i=n;i>0;i--)
	{
		for(int j=n;j>i;j--)//回代 
			 a[i][n+1]-=a[i][j]*ans[j];
			 if(a[i][i]==0)
			 {
			 	if(a[i][n+1]==0)puts("0");
			 	else puts("-1");
			 	return;//回代的时候也要判断解 
			 }
			 ans[i]=a[i][n+1]/a[i][i];
		}
		for(int i=1;i<=n;i++)
		{
			if(ans[i]==0)printf("x%d=%d\n",i,0);
			else printf("x%d=%.2lf\n",i,ans[i]);
		}
}	
bool check()
{
	int i,j;
	for(i=1;i<=n;i++)
	{ 
	for(j=1;j<=n;j++)if(a[i][j]!=0)break;//找第一个不为0的数
	if(j>n)//如果全都为0
	{
	if(a[i][n+1]==0){puts("0");return 0;}//等号右边为0，有无数解 
	else 
	{
	puts("-1");//无解 
	return 0;
	}
	} 
	 } 
	 return 1;
}
int main(){
	init();
	if(check())output();
	return 0;
}
