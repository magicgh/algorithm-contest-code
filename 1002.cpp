#include<iostream>
#include<algorithm>
using namespace std;
long long n,r,t[1005]={0},a[1005]={0},i,j=0,Min=0;
int main(){
  cin>>n>>r;
  for(i=1;i<=n;i++)cin>>t[i];
  sort(t+1,t+n+1);
 for(i=1;i<=n;i++)
{
  	j++;
  	if(j==r+1)j=1;
  	a[j]+=t[i];
  	Min+=a[j];
  }
  cout<<Min;
  	return 0;
}
