#include<iostream>
using namespace std;
int main()
{
int a,b,i;
while(cin>>a>>b)
{
	int ans=1;
	if(a==0&&b==0)break;
	else 
	{
		for(i=1;i<=b;i++)ans=(ans*a)%1000;
		cout<<ans%1000<<endl;
	}
}
return 0;
}
