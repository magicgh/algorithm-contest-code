#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
int v,n,vi[10005]={0},wi[10005]={0},f[10005]={0},i,j;
cin>>v>>n;
for(i=1;i<=n;i++)cin>>wi[i]>>vi[i];
for(i=1;i<=n;i++)
  for(j=vi[i];j<=v;j++)
 f[j]=max(f[j],f[j-vi[i]]+wi[i]);
  int Max=f[0];
  for(i=1;i<=v;i++)Max=max(Max,f[i]);
  cout<<Max;
	return 0;
}