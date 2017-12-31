#include<iostream>
using namespace std;
int main(){
  long long a[1005]={0},i,k,x,y,z,sum=0;
  cin>>x>>y>>z;
  a[1]=1;
  for(i=1;i<=z+1;i++)
  for(k=1;k<=z+1;k++)
   a[i+k*x+2]+=y*a[i];
   for(i=1;i<=z+1;i++)sum+=a[i];
  cout<<sum<<endl;
  return 0;
}