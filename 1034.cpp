#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;
int n,Max=0,x[705],y[705],cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
	    cnt=2;
		for(int k=j+1;k<=n;k++)
			if((x[i]-x[k])*(y[j]-y[k])-(x[j]-x[k])*(y[i]-y[k])==0)cnt++;
			Max=max(Max,cnt);
	}
	printf("%d",Max);
	return 0;
}