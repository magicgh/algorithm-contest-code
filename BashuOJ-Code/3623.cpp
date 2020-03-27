#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n;
inline int phi(int x)
{
	int ans=x;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			ans-=ans/i;
			while(x%i==0)x/=i;
		}
	}
	if(x>1)ans-=ans/x;
	return ans;
}
int main(){
	while(cin>>n&&n)
	{
		cout<<phi(n)<<endl;
	}
	return 0;
}
