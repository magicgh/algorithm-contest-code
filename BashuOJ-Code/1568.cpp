#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[1000005]={0},k,i;
int main(){
   a[1]=a[2]=1;
   while(cin>>k)
   {
   	i=3;
   	while(a[i]<=k)
   	{
   	i++;a[i]=a[i-1]+a[i-2];
	   }
   	cout<<a[i-1]*a[i-1]+a[i-2]*a[i-2]<<endl;
	   	
   }
	return 0;
}
