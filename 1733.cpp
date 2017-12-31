#include<iostream>
using namespace std;
int a[10005]={0};
int main()
{
int n,i;
cin>>n;
a[1]=1;
a[2]=1;
for(i=3;i<=n;i++)a[i]=(a[i-1]+a[i-2])%7654321;
cout<<a[n];
return 0;
}
