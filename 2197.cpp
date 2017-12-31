#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n;
	double sum=0,a[10005]={0};
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1);
	cout<<fixed<<setprecision(6)<<sum/n<<endl;
	if(n%2==1)cout<<fixed<<setprecision(6)<<a[n/2+1];
	else cout<<fixed<<setprecision(6)<<(a[n/2]+a[n/2+1])/2;
	return 0;
}
