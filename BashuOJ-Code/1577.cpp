#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long f(int n,int k)
{
	if(n<k||k==0)return 0;
	if(k==1||k==n)return 1;
	return f(n-1,k-1)+k*f(n-1,k);
}
int main(){
	int n,k;
	cin>>n>>k;
	cout<<f(n,k);
	return 0;
}
