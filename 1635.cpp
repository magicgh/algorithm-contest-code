#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long n,a[101005]={0},temp[101005]={0},js=0;
void f(long long l,long long r)
{
	if(l==r)return;
	long long mid=(l+r)/2;
	f(l,mid);
	f(mid+1,r);
	long long i=l,j=mid+1,p=l;
	 while(i<=mid&&j<=r)
	 {
	 	if(a[i]>a[j])temp[p++]=a[j++],js+=mid-i+1; 
		else temp[p++]=a[i++];
	 }
	 while(i<=mid)temp[p++]=a[i++];
	 while(j<=r)temp[p++]=a[j++];
	 for(i=l;i<=r;i++)a[i]=temp[i];
	return;
}
int main(){
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	f(1,n);
	cout<<js;
	return 0;
}
