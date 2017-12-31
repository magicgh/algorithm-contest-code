#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int n,m,k,a,b,c,i,j,ans=0;
	int ai[505]={0},bi[505]={0},p[505]={0},js=0;
	cin>>n>>m>>k;
	for(i=1;i<=k;i++)cin>>p[i];
	for(i=1;i<=n;i++)cin>>ai[i]>>bi[i];
	for(i=1;i<n;i++) 
	for(j=i+1;j<=n;j++)if(ai[i]<ai[j])swap(ai[i],ai[j]),swap(bi[i],bi[j]);
	for(i=1;i<=n;i++)
	for(j=1;j<=k;j++)
	{
	if(js>m-1)break;
	if(p[j]&&bi[i]==j)ans+=ai[i],p[j]--,js++;
	}
	cout<<ans;
	return 0;
}