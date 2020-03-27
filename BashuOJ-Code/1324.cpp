#include<iostream>
#include<algorithm> 
using namespace std;
long long a[10005]={0},n,i,sum=0;
int main(){
	cin>>n;
  for(i=1;i<=n;i++)cin>>a[i];
      sort(a+1,a+n+1);
       for(i=2;i<=n;i++)
       {
       	a[i]+=a[i-1];
       	  sum+=a[i];
       	  sort(a+1,a+n+1); 
       }
       cout<<sum;
	return 0;
}
