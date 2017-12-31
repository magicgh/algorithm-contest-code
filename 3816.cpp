#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	long long n;
	cin>>n;
	if(n%4==1)cout<<1;
	if(n%4==2)cout<<n+1;
	if(n%4==3)cout<<0;
	if(n%4==0)cout<<n;
	return 0;
}
