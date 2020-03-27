#include<iostream>
using namespace std;
int i,j,n,m,a[31][31]={0};
int main()
{
	cin>>n>>m;
	a[1][0]=1;
	for(i=1;i<=m;i++)
	{
	a[1][i]=a[2][i-1]+a[n][i-1];
	for(j=2;j<n;j++)a[j][i]=a[j-1][i-1]+a[j+1][i-1];
	a[n][i]=a[n-1][i-1]+a[1][i-1];
}
cout<<a[1][m]<<endl;
	return 0;
}
