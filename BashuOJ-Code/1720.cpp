#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int m,n,a[55][55],f[55][55][55][55];
int main(){
cin>>m;
memset(a,0,sizeof(a));
memset(f,0,sizeof(f));
for(int i=1;i<=m;i++)
   for(int j=1;j<=m;j++)cin>>a[i][j];
   f[2][1][1][1]=a[1][1];
   for(int k=3;k<=m+m;k++)
      for(int i=1;i<=m;i++)
         for(int j=1;j<=m;j++)
           for(int w=1;w<=m;w++)
         {
         	int Max=-0x7fffffff;
         	Max=max(Max,f[k-1][i][j][w]);
         	Max=max(Max,f[k-1][i-1][j][w]);
         	Max=max(Max,f[k-1][i][j-1][w]);
         	Max=max(Max,f[k-1][i][j][w-1]);
         	Max=max(Max,f[k-1][i-1][j-1][w]);
         	Max=max(Max,f[k-1][i-1][j][w-1]);
         	Max=max(Max,f[k-1][i][j-1][w-1]);
         	Max=max(Max,f[k-1][i-1][j-1][w-1]);
         	Max+=a[i][k-i];
         	if(i!=j)Max+=a[j][k-j];
         	if(i!=w&&j!=w)Max+=a[w][k-w];
         	f[k][i][j][w]=Max;
		 }
		 cout<<f[m+m][m][m][m];
 	return 0;
}
