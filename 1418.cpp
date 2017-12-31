#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct Tom
{
	int st,ed,vl;
}a[300005];
int n,maxv=-0x7fffffff,f[300005];
bool cmp(const Tom &a,const Tom &b)
{
	return a.ed<b.ed;
}
int main(){
	cin>>n;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
	cin>>a[i].st>>a[i].ed>>a[i].vl;
	maxv=max(maxv,a[i].ed);
	}
	sort(a+1,a+n+1,cmp);
	int j=1;
	for(int i=1;i<=maxv;i++)
	{
		f[i]=f[i-1];
		while(a[j].ed==i)
		{
			f[i]=max(f[i],f[a[j].st]+a[j].vl);j++;
		}                 
	}
	cout<<f[maxv];
	return 0;
}