#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int M=100000;
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
int N,B,Get=0,ans=0,a[100005]={0},Hash[200005]={0};
int main(){
	N=GetInt();
	B=GetInt();
	for(int i=1;i<=N;i++)
	{
	a[i]=GetInt();
	if(a[i]==B)Get=i;
	}
	int Rmax=0,Rmin=0;
	Hash[M]=1;
	for(int i=Get+1;i<=N;i++)
	{
		Rmax=a[i]>B?Rmax+1:Rmax;
		Rmin=a[i]<B?Rmin+1:Rmin;
		Hash[Rmax-Rmin+M]++;
	}
	int Lmin=0,Lmax=0;
	for(int i=Get-1;i>=1;i--)
	{
		Lmax=a[i]>B?Lmax+1:Lmax;
		Lmin=a[i]<B?Lmin+1:Lmin;
		ans+=Hash[Lmin-Lmax+M];
	}
	printf("%d",ans+Hash[M]);
	return 0;
}

