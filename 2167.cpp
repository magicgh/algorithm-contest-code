#include<iostream>
using namespace std;
int v[105][105]={0},f[105][105]={0},i,j,k,m,n,t;
int main() 
{
cin>>m>>n;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)cin>>v[i][j];
for(i=1;i<=n;i++)
for(j=0;j<=m;j++)
for(k=0;k<=j;k++)
if(f[i][j]<f[i-1][k]+v[i][j-k]){ 
f[i][j]=f[i-1][k]+v[i][j-k];
t=f[i][j];
}
cout<<t;
return 0;
}
