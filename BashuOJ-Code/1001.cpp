#include<iostream>
using namespace std;
int a[105]={0},b[105]={0},c[105]={0},n;
int main()
{
   int i,j,Max=0;
   cin>>n;
   for(i=1;i<=n;i++){cin>>a[i];b[i]=1;c[i]=1;}
   for(i=2;i<=n;i++)
   for(j=1;j<i;j++)
   if(a[i]>a[j]&&b[j]+1>b[i])b[i]=b[j]+1;
   for(i=n-1;i>=1;i--)
   for(j=n;j>i;j--)
   if(a[i]>a[j]&&c[j]+1>c[i])c[i]=c[j]+1;
   for(i=1;i<=n;i++)if(b[i]+c[i]>Max)Max=b[i]+c[i];
cout<<n-Max+1;
return 0;
}