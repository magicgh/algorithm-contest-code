#include<iostream>
#include<cstdio>
using namespace std;
int b,t,k,a;
int F(int t)
{
	if(t==0)return 1;
	int tmp=F(t/2)%k;
	tmp=(tmp*tmp)%k;
	if(t%2==1)tmp=(tmp*b)%k;
	return tmp;
}
int main()
{
	cin>>b>>t>>k;
	int tmpb=b;
	b%=k;
	printf("%d\n",F(t));
	return 0;
}