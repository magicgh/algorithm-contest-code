#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[100005]={0},b[100005]={0},w=0,ans=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)b[++w]=a[i+1]-a[i];
	sort(b+1,b+w+1);
	for(int i=1;i<=m;i++)ans+=b[i];
	cout<<ans;
	return 0;
}
