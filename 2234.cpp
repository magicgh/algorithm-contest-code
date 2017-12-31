#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,k,a[200005],b[200005];
int main(){
	cin>>n;
	int pt=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)cin>>b[i];
	int l,r,mid,len=1;
	memset(a,0,sizeof(a));
	a[1]=b[1];
	for(int i=2;i<=n;i++)
	{
		l=1,r=len;
		if(a[len]<b[i]){a[++len]=b[i];continue;}
		while(l<=r)
		{
			mid=(l+r)/2;
			if(b[i]>a[mid])l=mid+1;
			else r=mid-1;
		}
		a[l]=b[i];
	}
	cout<<n-len;
	return 0;
}