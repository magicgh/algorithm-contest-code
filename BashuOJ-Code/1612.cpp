#include<iostream>
using namespace std;
long long f[505]={0},i,a,b,k,n,t=0;
int main(){
cin>>n>>k;
for(i=1;i<=k;i++){cin>>a>>b;f[b]=a;}
for(i=1;i<=n;i++)if(f[i]==0)t++;
cout<<t<<endl;
for(i=1;i<=n;i++)if(f[i]==0)cout<<i<<' ';

	return 0;
}
