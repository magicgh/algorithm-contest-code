#include<iostream>
using namespace std;
long long n,m,a[1005][1005]={0},i,j,Max=0;
int main()
{
cin>>n>>m;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
cin>>a[i][j];
for(i=1;i<=n;i++)
{

for(j=1;j<=m;j++)
{

if(a[i][j]==1)a[i][j]=1+min(a[i-1][j],min(a[i-1][j-1],a[i][j-1]));
if(Max<a[i][j])Max=a[i][j];
}
}
cout<<Max;
return 0;
}
