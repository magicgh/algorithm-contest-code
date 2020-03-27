#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a[5005],f[5005],t[5005];
int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)cin>>a[i],f[i]=1,t[i]=1;
	for(int i=2;i<=n;i++)
	   for(int j=1;j<i;j++)
	   {
	   if(a[i]<a[j]&&f[j]+1>f[i])f[i]=f[j]+1,t[i]=t[j];
	   else if(a[i]<a[j]&&f[j]+1==f[i])t[i]+=t[j];
	   if(a[i]==a[j])f[j]=t[j]=0;
	   t[i]%=10000;
	   t[j]%=10000;
	   }
	   int Max=-0x7fffffff,Maxn=0;
	   long long ans=0;
	   for(int i=1;i<=n;i++)Max=max(Max,f[i]);
	   for(int i=1;i<=n;i++)if(f[i]==Max)ans=(ans+t[i])%10000;
	   /*
	   Consider this condition:(the queue of a[i] is all different)
	   f[i]  3   3  
	   t[i]  2   3 
	   */
	   cout<<Max<<' '<<ans%10000;
	return 0;
}