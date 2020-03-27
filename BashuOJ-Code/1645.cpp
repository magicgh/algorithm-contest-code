#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a[105],F[105][105];
int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	memset(F,0,sizeof(F));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i-1]>>a[i];
		F[i][i]=0;
	}
	for(int i=1;i<n;i++)
	   for(int j=1;j<=n-i;j++)
	   {
	   	int end=i+j;
	   	F[j][end]=0x7fffffff;
	   	for(int k=j;k<end;k++)
	   	{
	   		F[j][end]=min(F[j][end],F[j][k]+F[k+1][end]+a[j-1]*a[k]*a[end]);
		   }
	   }
	   cout<<F[1][n];
	return 0;
}