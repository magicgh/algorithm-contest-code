/*
ID: baymax01
PROG: milk2
LANG: C++                  
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
bool Check[1000005];
int a,b,Max=-0x7fffffff,Min=0x7fffffff,m1,m2;
int main(){
	memset(Check,0,sizeof(Check));
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cin>>a>>b;
	Max=max(Max,b);
	Min=min(Min,a);
	for(j=a;j<b;j++)Check[j]=1;
	}
	int k=0;
	j=0;
	m1=m2=-0x7fffffff;
	for(i=Min;i<=Max;i++)
	{
		if(Check[i]) 
		{
			j++;
			m2=max(m2,k);
			k=0;
			
		}
		if(!Check[i])
		{
			k++;
			m1=max(m1,j);
			j=0;
		}
	}
	cout<<m1<<' '<<m2<<endl;
	return 0;
}
