#include<iostream>
using namespace std;
long long c[1005][1005]={0},n,k,i,j;
int main()
{
cin>>n>>k;
for(i=0;i<=n;i++)c[i][0]=1;c[i][i]=1;
for(i=1;i<=n;i+=1)
for(j=1;j<=k;j+=1)
c[i][j]=(c[i-1][j]+c[i-1][j-1])%100003;
cout<<c[n][k];
return 0;
}
