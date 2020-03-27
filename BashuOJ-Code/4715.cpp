#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int main(){
	long long ans=0,n,a;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a,ans^=a;
	cout<<ans;
	return 0;
}
