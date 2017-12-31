#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,f[5005][5005];
string s;
int main(){
	cin>>n>>s;
	s=' '+s;
	int t=s.length();
	for(int i=1;i<=n;i++)f[0][i]=n-i+1,f[i][n+1]=i;
	for(int i=1;i<=n;i++)
	   for(int j=n;j>=i;j--)
	   {
	   	if(s[i]==s[j])f[i][j]=f[i-1][j+1];
	   	else f[i][j]=min(f[i-1][j],f[i][j+1])+1;
	   }
	   int Min=0x7fffffff;
	   for(int i=0;i<=n;i++)
	   {
	   	Min=min(Min,f[i][i+1]);
	   	if(i>0)Min=min(Min,f[i][i]);
	   }
	   cout<<Min;
	return 0;
}
