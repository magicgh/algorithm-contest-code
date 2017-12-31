/*
1. 1<=a[i]<=m(1<=i<=m)
2. a[n+1]=m
3. 存在xi(1<=i<=n=1)使∑xi*a[i]=1有解
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int a[65]={0},prime[65]={0},len=0;
int n,m;
long long ans=0,sum=0;
void Prime()//分解质因数 
{	
    int tt=m;
	for(int i=2;i*i<=tt;i++)
	{
		if(tt%i==0)prime[++len]=i;
		while(tt%i==0)tt/=i;	
	}
	if(tt!=1)prime[++len]=tt;//获取最后一个质因数，a[n+1]=m 
	
}
inline void DFS(int pos,int cnt,int total)//pos质因数的位置，cnt统计个数 
{
	if(cnt==total)
	{
		int tmp=m;
		for(int i=1;i<=total;i++)tmp/=a[i];//算可填数字的个数
		long long temp=1;
		for(long long i=1;i<=n;i++)temp*=tmp;
		sum+=temp;
		return;
	}
	for(int i=pos+1;i<=len;i++)a[cnt+1]=prime[i],DFS(i,cnt+1,total);//更新 
}
inline int GetInt()	
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	n=GetInt(),m=GetInt();	
	Prime();//建表
	for(int i=1;i<=len;i++)//容斥原理 
	{
		sum=0;
		DFS(0,0,i);
		if(i&1)ans-=sum;
		else ans+=sum;
	}
	long long tt=1;
	for(long long i=1;i<=n;i++)tt*=m;	
	printf("%lld",ans+tt); 
	return 0;
}
