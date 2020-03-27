#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct produce
{
	int k,m;
} W[1005];
int n,a[1005]={0},b[1005]={0},ans[1005]={0};
bool cmp (produce aa,produce bb)
{
	return aa.m<bb.m;
}
int main()
{
	cin>>n;
	int k1=0,k2=n+1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)W[i].m=min(a[i],b[i]),W[i].k=i;
	sort(W+1,W+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
	if(W[i].m==a[W[i].k])ans[++k1]=W[i].k;//前存 
	else ans[--k2]=W[i].k;//后存 
} 
	int ta=0,tb=0;
	for(int i=1;i<=n;i++)
	{
		ta+=a[ans[i]];
		if(ta>tb)tb=ta;
		tb+=b[ans[i]];
	}
	cout<<tb<<endl;
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
