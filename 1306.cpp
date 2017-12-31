#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int a[1010][1010],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
	  cin>>a[i][j];
	   for(int k=1;k<=n;k++)
	      for(int i=1;i<=n;i++)
	         for(int j=1;j<=n;j++)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	    int Min=0x7fffffff,MinNo=0;
	    for(int i=1;i<=n;i++)
	    {
		    int sum=0;
	    	for(int j=1;j<=n;j++)sum+=a[i][j];
	    	if(sum<Min)Min=sum,MinNo=i;
		}
		cout<<MinNo<<' '<<Min;
	return 0;
}
