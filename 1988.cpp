#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a[20010]={0},total=0,Min=0x7fffffff;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],total+=a[i];
	total/=n;
	for(int i=1;i<=n;i++)a[i]-=total,a[n+i]=a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt=0,t=a[i];
		for(int j=i;j<=n+i-1;j++)cnt+=abs(t),t+=a[j+1];
		Min=min(Min,cnt);
	}
	cout<<Min;
	return 0;
}
