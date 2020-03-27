#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a[100005],b[100005];
int main(){
	int x;
	while(cin>>n)
	{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
	    cin>>x;
	    b[i]=a[x];
	}
	
	int l,r,mid,len=1;
	memset(a,0,sizeof(a));
	a[1]=b[1];
	for(int i=2;i<=n;i++)
	{
	   l=1,r=len;
	   if(b[i]>a[len]){a[++len]=b[i];continue;}
	   while(l<=r)
	   {
	   	mid=(l+r)/2;
	   	if(a[mid]<b[i])l=mid+1;
	   	else r=mid-1;
	   }
	   a[l]=b[i];
	}
	cout<<len<<endl;
	}
	return 0;
}