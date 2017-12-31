#include<iostream>
using namespace std;
long n,i,a[1005]={0};
int main(){
   cin>>n;
   a[1]=1;a[2]=3;
   for(i=3;i<=n;i++)a[i]=(a[i-1]+a[i-2]*2)%12345;
   cout<<a[n];
	return 0;
}
