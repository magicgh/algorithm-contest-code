#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int m,n,a[15][15],f[55][15][15],x,y;
int main(){
cin>>m;
memset(a,0,sizeof(a));
memset(f,0,sizeof(f));
while(cin>>x>>y,(x!=0&&y!=0))
{
	cin>>a[x][y];
}
f[2][1][1]=a[1][1];
   for(int k=3;k<=m+m;k++)
      for(int i=1;i<=m;i++)
         for(int j=1;j<=m;j++)
         {
         	int Max=-0x7fffffff;
         	Max=max(Max,f[k-1][i][j]);
         	Max=max(Max,f[k-1][i-1][j]);
         	Max=max(Max,f[k-1][i][j-1]);
         	Max=max(Max,f[k-1][i-1][j-1]);
         	Max+=a[i][k-i];
         	if(i!=j)Max+=a[j][k-j];
         	f[k][i][j]=Max;
		 }
		 cout<<f[m+m][m][m];
 	return 0;
}