#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm> 
using namespace std;
int main() {
int n,a[100005]={0},ans=0;
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n;i++)
{
	if(ans+1<a[i])break;//断点 
	ans+=a[i];
}
cout<<ans+1; 
	return 0;
}
