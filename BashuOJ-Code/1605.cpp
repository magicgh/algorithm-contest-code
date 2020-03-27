#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int f[855][855]={0},n,i,j,k,a[50]={0},s=0;
double m=0,p,t;
int main(){
	cin>>n;
	for(i=0;i<n;i++) {cin>>a[i];s+=a[i];}
	memset(f,0,sizeof(f));
f[0][0]=1;
for(i=1;i<=n;i++)
for(j=s/2;j>=0;j--)
for(k=s/2;k>=0;k--)
if(f[j][k]){f[j+a[i]][k]=1;f[j][k+a[i]]=1;}
p=s/2.0;
for(i=1;i<p;i++)
      for(j=1;j<=i;j++)
        if(f[i][j]==1&&((i+j)>(s-i-j))&&((i-j)<(s-i-j)))
        {  t=p*(p-i)*(p-j)*(p-(s-i-j));
           if(m<t) m=t;}
      if(m<=0)cout<<"-1";
         else cout<<int(sqrt(m)*100);
	return 0;
}
