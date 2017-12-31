#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,s,k,a[505][505]={0},x,y;
int main(){
	cin>>n>>s>>k;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)cin>>a[i][j];
	  for(int i=1;i<=k;i++)
	  {
	  	int Max=-0x7fffffff,Min=0x7fffffff;
	  	cin>>x>>y;
	  	for(int j=x;j<=x+s-1;j++)
	  	 for(int k=y;k<=y+s-1;k++)
	  	 {
	  	 	Max=max(Max,a[j][k]);
	  	 	Min=min(Min,a[j][k]);
		   }
		   cout<<Max-Min<<endl;
	  }
	return 0;
}
