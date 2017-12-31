#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int m,n,i,j,v[105],w[105],f[30005];
	cin>>m>>n;
	memset(v,0,sizeof(v));
	memset(w,0,sizeof(w));
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)cin>>v[i]>>w[i],w[i]*=v[i];
	for(i=1;i<=n;i++)
	   for(j=m;j>=v[i];j--)f[j]=max(f[j],f[j-v[i]]+w[i]);
	   cout<<f[m];
	return 0;
}