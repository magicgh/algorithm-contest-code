#include<iostream>
using namespace std;
long long n,a[100005]={0},s[100005]={0},ans=-0x7fffffff,Min,Max;
int main()
{
	bool flag=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<0)flag=1;
		s[i]=s[i-1]+a[i];
	}
	if(flag==0)
	{
		ans=0;
		for(int i=1;i<=n;i++)ans+=a[i];
	}
	else
	{
	Min=Max=s[n];
    for (int i=n-1;i>=1;i--)
      {
	    ans=max(ans,max(Max-s[i],s[i]+s[n]-Min));
		Max=max(Max,s[i]);
		Min=min(Min,s[i]);    
      }
	  }
cout<<ans;
return 0;	
}