#include<iostream>
#include<cstdio>
using namespace std;
int i,j,m,n,w,h,a[3002][3002],s[3002][3002],maxn=0;
int main(){
	cin>>m>>n>>w>>h;
for(i=1;i<=m;i++)
for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
  for(i=w;i<=m;i++)
  for(j=h;j<=n;j++)
        if(maxn<s[i][j]-s[i][j-h]-s[i-w][j]+s[i-w][j-h])
           maxn=s[i][j]-s[i][j-h]-s[i-w][j]+s[i-w][j-h];
  cout<<maxn<<endl;
 
	return 0;
}
