#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int m,n,a[55],s[55][55],f[55][55];
int GetInt()
{
	char t;
	int ans=0;
	while(t=getchar(),t>='0'&&t<='9')
	{
		ans=ans*10+(t-'0');
	}
	return ans;
}
void Preduce(int x,int y)
{
	for(int i=x;i<=y;i++)s[x][y]=s[x][y]*10+a[i];
}
int main(){
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	memset(f,0,sizeof(f));
	n=GetInt();
	m=GetInt();
	for(int i=1;i<=n;i++)a[i]=getchar()-'0';
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)Preduce(i,j);
	   for(int i=1;i<=n;i++)f[0][i]=s[1][i];
	   
	for(int i=1;i<=m;i++)
	   for(int j=i+1;j<=n;j++)
	      {
	      	for(int k=i;k<=j-1;k++)
	      	f[i][j]=max(f[i][j],f[i-1][k]*s[k+1][j]);
		  }
	printf("%d",f[m][n]);
	return 0;
}
