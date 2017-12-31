#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int r,c,e,n,i,j,k,Lake[105][105]={0};
	int ans=0;
	int t1,t2,t3;
	cin>>r>>c>>e>>n;
	for(i=1;i<=r;i++)
	  for(j=1;j<=c;j++)cin>>Lake[i][j];
	  for(i=1;i<=n;i++)
	  {
	  	int Max=0;
	  	cin>>t1>>t2>>t3;
	  	for(j=t1;j<=t1+2;j++)
	  	   for(k=t2;k<=t2+2;k++)Max=max(Max,Lake[j][k]);
	  	   Max-=t3;
	  	   for(j=t1;j<=t1+2;j++)
	  	   for(k=t2;k<=t2+2;k++)if(Lake[j][k]>Max)Lake[j][k]=Max;
	  }
	  for(i=1;i<=r;i++)
	  for(j=1;j<=c;j++)if(e-Lake[i][j]>0)ans=ans+(e-Lake[i][j]);
	  cout<<72*72*ans<<endl;
	return 0;
}