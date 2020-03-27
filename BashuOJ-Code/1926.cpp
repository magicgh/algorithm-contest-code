#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long a[20]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200};
long long ans=0,n,t,num;;
int main()
{
cin>>n>>t;
ans=a[n];
for(int i=1;i<=t;i++)
{
	cin>>num;
	ans/=a[num];
}
cout<<ans;
return 0;
}