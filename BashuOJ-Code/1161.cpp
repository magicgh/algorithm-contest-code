#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
int n,x,y;
cin>>n>>x>>y;
if(y%x==0)cout<<n-y/x;
if(y%x!=0)cout<<n-y/x-1;
return 0;
}