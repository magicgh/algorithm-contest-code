#include<iostream>
using namespace std;
int main()
{
int n,ans=1;
cin>>n;
for(int i=1;i<=n;i++)
{
	if (ans>1000000) ans=ans%1000000; 
	ans*=i;
	while(ans%10==0)ans/=10;
}
cout<<ans%10;
return 0;
}
