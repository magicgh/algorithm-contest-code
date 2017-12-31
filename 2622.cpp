#include<iostream>
using namespace std;
int a[1005][2],n,x,y,t,i;
int main()
{  cin>>x>>y>>n;
   for(i=1;i<=y;i++)a[i][0]=a[i][1]=-1;
   for(i=1;i<=n;i++)
   {  cin>>t;
	  cin>>a[t][0]>>a[t][1];
   }
   int ans=y;
   for(;y>=1;y--)
      if(a[y][0]<=x&&a[y][1]>=x)
      {  ans+=5;
         x=a[y][1];
      }
   cout<<ans<<endl;
   return 0;
}