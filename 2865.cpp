#include<iostream>
#include<algorithm> 
#include<cstdio>
using namespace std;
long long n,a[100010]={0},i;
int main()
{
   scanf("%d",&n);
   for(i=1;i<=n;i++)scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   for(i=1;i<=n;i++)printf("%d ",a[i]);
return 0;
}
