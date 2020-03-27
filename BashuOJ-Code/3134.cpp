#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,s,cnt=0,a[200005]={0};
long long erfen(int x,int l,int r)
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]+x>s)r=mid-1;
		if(a[mid]+x<=s)l=mid+1;
	}
	return l-1;
}
int main(){
	scanf("%lld%lld",&n,&s);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		int pos=erfen(a[i],i+1,n);
		cnt+=(n-pos);
		if(a[pos]+a[i]>s&&i!=pos)cnt++;
	}
	printf("%lld",cnt);
	return 0;
}
