#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[100005]={0},i;
int main(){
	cin>>n>>m;
for(i=0;i<n;i++)cin>>a[i];
for(i=0;i<m;i++)next_permutation(a,a+n);
for(i=0;i<n;i++)cout<<a[i]<<' ';
	return 0;
}
