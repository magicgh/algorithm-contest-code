#include<iostream>
using namespace std;
long long a[1005][1005]={0},n,i,j,m,x,y;
int main(){
    cin>>n;
    for(i=1;i<=n;i++){a[1][i]=1;a[i][1]=1;}
    for(i=2;i<=n;i++)
    {
    for(j=2;j<=n;j++)
    {
    a[i][j]=(a[i-1][j]+a[i][j-1])%100003;
}
}
   cin>>m;
   for(i=1;i<=m;i++)
   {
   	cin>>x>>y;
   	a[x][y]=0;
   	if(x==1)
   	{
   		for(j=y;j<=n;j++)a[1][j]=0;
   	}
   	if(y==1)
   	{
   		for(j=x;j<=n;j++)a[j][1]=0;
   	}
   }
   
for(i=2;i<=n;i++)
    {
    for(j=2;j<=n;j++)
    {
    if(a[i][j]>0)a[i][j]=(a[i-1][j]+a[i][j-1])%100003;
}
}
cout<<a[n][n];

    return 0;
}