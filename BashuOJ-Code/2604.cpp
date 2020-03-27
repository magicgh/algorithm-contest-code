#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[2000005]={0},b[2000005]={0},i,head=1,tail=1;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {scanf("%d",&a[i]);tail++;
     if(i>k)if(b[head]<=i-k)head++;
     while(a[b[tail-1]]>=a[i]&&tail>head)tail--;
	 b[tail]=i;
     if(i>=k)cout<<a[b[head]]<<' ';
     }
	 cout<<endl;
    head=1;tail=1;
    for(i=1;i<=n;i++)
    {
     if(i>=k)if(b[head]<=i-k)head++;
	 tail++;
     while(a[b[tail-1]]<=a[i]&&tail>head)tail--;
	 b[tail]=i;
     if(i>=k)cout<<a[b[head]]<<' ';
     }
    return 0;
}