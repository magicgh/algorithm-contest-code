#include<iostream>
#include<algorithm>  
using namespace std;
long long  n,m,i,j,a[5005]={0},b[5005]={0},sum=0;
int main()
{
  
    cin>>n>>m;
  for(i=1;i<=n;i++)cin>>a[i];
  for(i=1;i<=m;i++)cin>>b[i];
  sort(a+1,a+n+1);
  sort(b+1,b+m+1);
  for(i=n;i>=1;i--)
  {
  for(j=m;j>=1;j--)
  {
  if(a[i]>b[j]&&b[j]!=0){sum++;a[i]=b[j]=0;}
  }
  }
  cout<<m-sum;
return 0;
}
