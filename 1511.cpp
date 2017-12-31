#include<iostream>
using namespace std;
int a[205],f[205][205]={0},n,k,t,Max=0;
int main(){
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i];	   
a[n+i]=a[i];	
}
for(int i=1;i<n;i++)     
for(int j=1;j<=2*n-i-1;j++)
{        
t=i+j;       	  
f[j][t]=0;       	  
for(int k=j;k<t;k++)
f[j][t]=max(f[j][t],f[j][k]+f[k+1][t]+a[j]*a[k+1]*a[t+1]);
if(f[j][t]>Max)Max=f[j][t];       
}    
cout<<Max<<endl;
return 0;
}