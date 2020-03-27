#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,a[1005]={0},t,total=0;
int main(){
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		memset(a,0,sizeof(a));
		for(int j=1;j<=t;j++)cin>>a[j];
		sort(a+1,a+t+1);
		total+=a[t];
	}
	cout<<"total="<<total;
	return 0;
}
