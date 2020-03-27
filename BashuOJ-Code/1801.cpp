#include<iostream>
using namespace std;
long long a,b;
int main()
{
while(cin>>a>>b)
{
	int a1=a%10,b1=b%4,ans=1;
	if(b!=0&&b1==0)b1=4;
	for(int i=1;i<=b1;i++)ans=ans*a1;
	cout<<ans%10<<endl;
}
return 0;
}
