#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a[105],s[105],Fmax[105][105],Fmin[105][105];
int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	memset(Fmax,0,sizeof(Fmax));
	memset(Fmin,0,sizeof(Fmin));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		Fmax[i][i]=Fmin[i][i]=0;
	}
	for(int i=1;i<n;i++)
	   for(int j=1;j<=n-i;j++)
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
	   cout<<Fmin[1][n]<<endl<<Fmax[1][n];
	return 0;
}
