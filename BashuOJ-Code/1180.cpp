#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	string a;
	cin>>a;
	int m,n=a.length();
	cin>>m;
	for(int i=n-m;i<n;i++)cout<<a[i];
	for(int i=0;i<n-m;i++)cout<<a[i];
	return 0;
}
