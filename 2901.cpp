#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[1000005]={0},b[1000005]={0};
int main(){
  int n,i,j;
  cin>>n;
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  b[n]=0;
  for(i=n;i>=1;i--)
   {
    for(j=i-1;j>=0&&a[j]<a[i];j--)b[j]=i;
    }
  for(i=1;i<=n;i++)cout<<b[i]<<" ";
    return 0;
}