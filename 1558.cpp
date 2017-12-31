#include<iostream>
using namespace std;
int main(){
    int n,f=0,i,x,j,k=0,t=0;
    cin>>n;
    int a[105];
    for(i=1;i<=n;i++){cin>>a[i];}
    cin>>x;
    for(i=1;i<=n;i++)
    {
      if(a[i]==x)
      {
      f=1;          
      a[i]=0;
      }
      }
      if(f==1)
      {
    for(j=1;j<=n;j++) 
    {
    if(a[j]>0)
    {
    cout<<a[j]<<" ";
    }
    }
      }
        if(f==0)
        {
          a[n+1]=x;
          for(i=1;i<n+1;i++)
          {
          for(j=i+1;j<=n+1;j++)
          {
            if(a[i]>a[j]){t=a[i];a[i]=a[j];a[j]=t;}
            }
            }
          for(i=1;i<=n+1;i++){cout<<a[i]<<" ";}
          }
   // system("pause");
    return 0;
}
