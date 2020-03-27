#include<iostream>
using namespace std;
long long m,n,f[205]={0},v[205]={0},mo[205]={0};
int main()
{
	int i,j,Max=0;
	cin>>m>>n;
	for(i=1;i<=n;i++)cin>>v[i]>>mo[i];
	for(i=1;i<=n;i++)
    for(j=v[i];j<=m;j++)
    f[j]=max(f[j],f[j-v[i]]+mo[i]);
    for(i=1;i<=m;i++)if(Max<f[i])Max=f[i];
    cout<<Max;
return 0;
}
