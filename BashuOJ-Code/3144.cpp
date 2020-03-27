
#include<iostream>
using namespace std;
long a[100005],b[100005],k[100005],g[100005],n,x,y,sum,i;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>b[i]>>g[i]>>k[i];
	cin>>x>>y;
	for(i=n;i>=1;i--)
	{
  if(x>=a[i]&&y>=b[i]&&x<=a[i]+g[i]&&y<=b[i]+k[i]){cout<<i;break;}
  }
	
   if(i==0) cout<<-1;
	return 0;
}
