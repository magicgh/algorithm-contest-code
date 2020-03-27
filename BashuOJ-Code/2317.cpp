#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a[20]={0},f[1005]={0};
int main(){
	for(int i=1;i<=10;i++)cin>>a[i];
	cin>>n;
	for(int i=1;i<=1000;i++)f[i]=0x7fffffff/2;
	f[0]=0;
	for(int i=1;i<=10;i++)
	{
	   for(int j=i;j<=n;j++)
	   {
	   f[j]=min(f[j],f[j-i]+a[i]);
       }
   }
       cout<<f[n];
	return 0;
}
