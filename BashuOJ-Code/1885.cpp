#include<iostream>
#include<cstdio>
using namespace std;
int n,m,fn[250][1020]={0},sum[1020],a[1020];
int main()
{
  cin>>n>>m;
  sum[0]=0;
  for(int i=1;i<=n;i++) 
  {scanf("%d",&a[i]);sum[i]=sum[i-1]+a[i];}
  for(int i=1;i<=m;i++)
   for(int j=i;j<=n;j++)
   {
     fn[i][j]=fn[i][j-1];
     for(int k=i-1;k<j;k++)
       if(fn[i-1][k]+sum[j]-sum[k]>fn[i][j]) fn[i][j]=fn[i-1][k]+sum[j]-sum[k];
   }
  cout<<fn[m][n]<<endl;
  return 0;    
}