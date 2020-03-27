#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
long long f[25][25]={0},n,m;
long long get_int()
{
	char t;
	int ans=0;
	while(t=getchar(),t>='0'&&t<='9')
	{
		ans=ans*10+(t-'0');
	}
	return ans;
}
int main(){
	n=get_int(),m=get_int();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)f[i][j]=1;
	for(int i=3;i<=n;i++)
	   for(int j=2;j<i;j++)f[i][j]=f[i-1][j]*j+f[i-1][j-1]*(i+1-j);
	   cout<<f[n][m];
	return 0;
}

