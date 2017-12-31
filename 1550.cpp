#include<iostream>
using namespace std;
int main(){
  int n,a[21][21],i,j,f1,f2,k;
  cin>>n;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      cin>>a[i][j];
      }
      }
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      {f1=0;f2=0;
       for(k=1;k<=n;k++)
         if(a[k][j]>a[i][j])
           f2=1;
       for(k=1;k<=n;k++)
         if(a[i][k]<a[i][j])
           f1=1;
       if(f1==0&&f2==0)
         cout<<"("<<i<<","<<j<<")"<<endl;
      }
  // system("pause");
    return 0;
}