#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a[105],s[105],Fmax[105][105],Fmin[105][105];
int Max=-0x7fffffff,Min=0x7fffffff;
int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	memset(Fmax,0,sizeof(Fmax));
	memset(Fmin,0,sizeof(Fmin));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[n+i]=a[i];
	}
	for(int i=1;i<=2*n;i++)
	{
		s[i]=s[i-1]+a[i];
		Fmax[i][i]=Fmin[i][i]=0;
	}
	for(int i=1;i<n;i++)
	   for(int j=1;j<=2*n-i;j++)
	   {
	   	int end=i+j;
	   	Fmax[j][end]=-0x7fffffff;
	   	Fmin[j][end]=0x7fffffff;
	   	for(int k=j;k<end;k++)
	   	{
	   		Fmax[j][end]=max(Fmax[j][end],Fmax[j][k]+Fmax[k+1][end]);
	   		Fmin[j][end]=min(Fmin[j][end],Fmin[j][k]+Fmin[k+1][end]);
		   }
		   Fmax[j][end]=Fmax[j][end]+(s[end]-s[j-1]);
		   Fmin[j][end]=Fmin[j][end]+(s[end]-s[j-1]);
	   }
	   for(int i=1;i<=n;i++)
	   {
	   	Max=max(Max,Fmax[i][n+i-1]);
	   	Min=min(Min,Fmin[i][n+i-1]);
	   }
	   cout<<Min<<endl<<Max;
	return 0;
}
