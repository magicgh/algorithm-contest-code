#include<iostream>
using namespace std;
int a[350][350]={0},b[350][350]={0},n,m,ans;
void one()
{  int c,i,j;
   cin>>n>>m;
   for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
       {
          cin>>c;
          a[i][j]=c+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
          if(c==0)b[i][j]=0;
             else b[i][j]=b[i][j-1]+1;
       }
}
void two()
{  int i,j,L,h,maxn,sum;
   ans=0;
   for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
       if(b[i][j]>0)
        {
          L=b[i][j];
          maxn=a[i][j]-a[i-1][j]-a[i][j-L]+a[i-1][j-L];
          h=i-1;
          while(h>=1&&b[h][j]>0)
           {
            if(b[h][j]<L)L=b[h][j];
            sum=a[i][j]-a[h-1][j]-a[i][j-L]+a[h-1][j-L];
            if(maxn<sum)maxn=sum;
            h--;
           }
          if(ans<maxn)ans=maxn;
        }
}
int main()
{
  one();
  two();
  cout<<ans<<endl;
    return 0;
}