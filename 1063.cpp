#include<iostream>
using namespace std;
long long n,f[1005]={0},i,j;
int main(){
    cin>>n;
    f[0]=f[1]=1;
    for(i=2;i<=n;i++)
    for(j=0;j<i;j++)
    f[i]+=f[j]*f[i-j-1];
    cout<<f[n];
	return 0;
}
