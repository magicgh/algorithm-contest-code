#include<iostream>
using namespace std;
int dg(int a,int b)
{
	int k=a/2;
	if(a==1)return 1;
	if(b<=k)return a-k+dg(k,k+1-b);
	if(b>k)return dg(a-k,a+1-b);
}
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<dg(n,m);
	return 0;
}
