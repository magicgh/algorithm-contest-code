#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int i,n;
	double h,a,b,ans=0;
	cin>>h>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		ans+=b;
		if(a>=h)break;
	}
	cout<<fixed<<setprecision(1)<<ans;
	return 0;
}