#include<iostream>
using namespace std;
int main()
{
 int n,i,j;
 cin>>n;
 string a[n+10],t;
 for(i=1;i<=n;i++)
 {
    cin>>a[i];
}
  for(i=1;i<n;i++)
  {
  for(j=i+1;j<=n;j++)
  {
  if(a[i]>a[j]) {t=a[i];a[i]=a[j];a[j]=t;}
}
}
for(int k=1;k<=n;k++)
{
  cout<<a[k]<<endl;
}
 
    
   
                  
 

return 0;
}
