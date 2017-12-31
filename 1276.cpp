#include<iostream>
using namespace std;
long long n,i,j;
string a[10005];
int main()
{
	cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<n;i++)
     for(j=i+1;j<=n;j++){if(a[i]+a[j]<a[j]+a[i])swap(a[i],a[j]);}
    for(i=1;i<=n;i++)cout<<a[i];
    return 0;
}