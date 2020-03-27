#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int n,a[1005]={0},i;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	int sum1=0,sum2=0;
	for(i=1;i<=n;i++)
	{
		sum1+=a[2*i];
		sum2+=a[2*i-1];
	}
	if(sum1==sum2)cout<<"no";
	else cout<<"yes";
	return 0;
}
