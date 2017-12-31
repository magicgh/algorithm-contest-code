#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int w,n,a[30005]={0},cnt=0;
	cin>>w>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]+a[n-i+1]>w)cnt++,--i,--n;
		else cnt++;
	}
	if(n%2==1)cnt++;
	cout<<cnt;
	return 0;
}
