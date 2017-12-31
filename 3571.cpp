#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;
int n,a[1005]={0},t=INT_MAX;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)
	{
	   t=INT_MAX;
	   for(int j=i+1;j<=n;j++)
	   {
	   	if(a[j]<a[i]&&t==INT_MAX)t=a[j];
	   	else if(a[j]<a[i]&&t<a[j]){printf("NO\n");return 0;}
	   }
	   }
	   printf("YES\n");
	return 0;
}
