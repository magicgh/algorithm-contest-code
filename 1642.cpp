#include <iostream>
using namespace std;
int sum,n,i,j,k,s[305][305],a[305][305],t;
int main()
{
   cin>>n;
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)cin>>a[i][j];
   for(i=1;i<=n;i++)s[1][i]=a[1][i];
   for(i=2;i<=n;i++)
   for(j=1;j<=n;j++)
        s[i][j]=s[i-1][j]+a[i][j]; 
   sum=-0x7fffffff;
   for(i=1;i<=n;i++)  
    {
      for(j=i;j<=n;j++)  
       {
         t=s[j][1]-s[i-1][1];  
         for(k=2;k<=n;k++) 
          {
            t=max(t,0)+s[j][k]-s[i-1][k];
            if(t>sum)sum=t;
          }
       }
    }
   cout<<sum;
   return 0;
}