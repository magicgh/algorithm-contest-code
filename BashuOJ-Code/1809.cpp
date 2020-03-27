#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
	int i,n,k,a;
int main(){
	while(cin>>n)
	{
		k=pow(2,n);
		int sum=(1+k)*k/2;
		for(i=1;i<k;i++)cin>>a,sum-=a;
		cout<<sum<<endl;
	}
	return 0;
}
