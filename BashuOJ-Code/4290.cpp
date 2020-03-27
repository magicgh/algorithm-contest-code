#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
using namespace std;
long i,j,k,js,a[105]={0},b[105]={0},n;
int main(){
cin>>n;
for(i=1;i<=n;i++)cin>>a[i];
for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
     for(k=j+1;k<=n;k++)if(a[i]==a[j]+a[k])b[i]=1;
     for(i=1;i<=n;i++)if(b[i]==1)++js;
     cout<<js;
	return 0;
}
