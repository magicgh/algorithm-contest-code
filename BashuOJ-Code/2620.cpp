#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int h,n,i,j,v[1005]={0},bag[45005]={0};
	cin>>h>>n;
	for(i=1;i<=n;i++)cin>>v[i];
	for(i=1;i<=n;i++)
	   for(j=h;j>=v[i];j--)bag[j]=max(bag[j],bag[j-v[i]]+v[i]);
	   cout<<bag[h];
	return 0;
}
