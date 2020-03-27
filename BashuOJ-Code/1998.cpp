#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n;
void f(int l,int r)
{
	while(l<r)
	{
	int mid=(l+r)/2,temp=int(mid*log10(mid))+1;
	if(temp>=n)r=mid;
	else l=mid+1;
	}
	cout<<l;
	return;
}
int main(){
	cin>>n;
	f(1,0xfffffff);
	return 0;
}