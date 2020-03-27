#include<iostream>
using namespace std;
long long m,n,f[505][505]={0},v[505]={0},mo[505]={0};
int main()
{
	int i,j,Max=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>mo[i]>>v[i];
	for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
{ f[i][j]=f[i-1][j];
    if(j>=v[i]&&f[i][j]<f[i-1][j-v[i]]+mo[i])f[i][j]=f[i-1][j-v[i]]+mo[i];
   }
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
	if(Max<f[i][j])Max=f[i][j];
    cout<<Max;
return 0;
}