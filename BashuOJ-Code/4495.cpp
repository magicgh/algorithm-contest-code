#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long  n,a[105]={0},b[105]={0},ans=0;
int main(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	ans=b[1]=a[1];
	for(i=2;i<=n;i++)
	{
	b[i]=a[i]*i-ans;
	ans+=b[i];
	}
	for(i=1;i<=n;i++)cout<<b[i]<<' ';
	return 0;
}
