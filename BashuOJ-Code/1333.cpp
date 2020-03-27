#include <iostream>
using namespace std;
int main()
{
	
	long long i,n,ans,t;
	while(cin>>n)
	{
		ans=0,t=1;
for(i=1;i<=n;i++)
{
	
 t*=i;
 while(t%10==0)t/=10;
 ans+=t%10;
 t%=10000000;
}
cout<<ans<<endl;

	}
	return 0;
}