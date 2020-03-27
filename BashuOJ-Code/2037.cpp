#include<iostream>
using namespace std;
long n,i,a[1005]={0},b[1005]={0};
int main(){
   cin>>n;
   a[1]=1;b[1]=2;
   for(i=2;i<=n;i++)
   {
   a[i]=(a[i-1]+b[i-1])%12345;
    b[i]=(2*a[i-1]+b[i-1])%12345;
    }
   cout<<(a[n]+b[n])%12345;
	return 0;
}
