#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int m,n,a[2005];
void Init()
{
	memset(a,0,sizeof(a));
	a[1]=a[0]=1;//倒存 
	return;
}
void Multi(int k)
{
	for(int i=1;i<=a[0];i++)a[i]*=k;
	for(int i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10; 
	}
while(a[a[0]+1]>0)
{
	a[0]++;
	a[a[0]+1]+=a[a[0]]/10;
	a[a[0]]%=10; 
}
return;
}
void Div(int k)
{
	int d=0;
	for(int i=a[0];i>=1;i--)
	{
		d=d*10+a[i];
		a[i]=d/k;
		d%=k;
	}
	while((!a[a[0]])&&a[0]>1)a[0]--;
	return;
}
int main(){
cin>>m>>n;
Init();
for(int i=1;i<=m;i++)
{
Multi(n-i+1);
Div(i);	
}	
for(int i=a[0];i>=1;i--)cout<<a[i];
	return 0;
}
