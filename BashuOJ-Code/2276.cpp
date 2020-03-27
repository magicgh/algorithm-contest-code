#include<iostream>
#include<cstdio>
using namespace std;
int a[1005][1005],L[1005][1005],R[1005][1005],h[1005][1005],n,m,ans;
void one()
{  int i,j,c;
   cin>>n>>m;
   for(i=1;i<=n;i++)
     {
       a[i][0]=0; h[i][0]=0;
       for(j=1;j<=m;j++)
        { scanf("%d",&c);
          a[i][j]=c+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
          if(c==0)h[i][j]=0; 
             else h[i][j]=h[i-1][j]+1;
        }
       L[i][0]=0;
       for(j=1;j<=m;j++)
         if(h[i][j]==0)L[i][j]=0;
                  else L[i][j]=L[i][j-1]+1;
       R[i][m+1]=0;
       for(j=m;j>=1;j--)
          if(h[i][j]==0)R[i][j]=0;else R[i][j]=R[i][j+1]+1;
   }
}
void two()
{  int x1,y1,x2,y2,maxn,i,j;
   ans=0;
   for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
       if(h[i][j]>0)
        {
          if(h[i][j]>1)
           {
            if(L[i][j]>L[i-1][j])L[i][j]=L[i-1][j];
            if(R[i][j]>R[i-1][j])R[i][j]=R[i-1][j];
           }
          x2=i;y2=j+R[i][j]-1;           
          x1=i-h[i][j]+1;y1=j-L[i][j]+1; 
          maxn=a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
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