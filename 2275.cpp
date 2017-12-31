#include<iostream>
#include<cstdio>
using namespace std;
long long a[1005][1005]={0},f[1005][1005]={0},n,i,j;
int main(){
     cin>>n;
     for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
     f[1][1]=a[1][1];
     for(i=2;i<=n;i++)
     {
       f[1][i]=f[1][i-1]+a[1][i];
       f[i][1]=f[i-1][1]+a[i][1];
       }
       for(i=2;i<=n;i++)
       {
         for(j=2;j<=n;j++)
         {
            f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
            }
            }
             cout<<f[n][n];
    //system("pause");
    return 0;
}