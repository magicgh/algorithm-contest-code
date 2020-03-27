#include<iostream>
using namespace std;
long n,a[1005]={0},total=0,i,js=0;
int main(){
cin>>n;
for(i=1;i<=n;i++)
{
cin>>a[i];
total+=a[i];
}
for(i=1;i<=n;i++)a[i]-=total/n;
for(i=1;i<=n;i++)
{
	if(a[i]==0)continue;
	else
	{
		++js;
		a[i+1]+=a[i];
		a[i]=0;
	}
}
cout<<js;
	return 0;
}
