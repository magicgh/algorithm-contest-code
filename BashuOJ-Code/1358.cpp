#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
string s1,s2;
int f[3005][3005]={0};
int main(){
	cin>>s1>>s2;
	int n1=s1.length();
	int n2=s2.length();
	s1=" "+s1;
	s2=" "+s2;
	for(int i=1;i<=n1;i++)
	   for(int j=1;j<=n2;j++)
	   {
	   	if(s1[i]==s2[j])f[i][j]=f[i-1][j-1]+1;
	   	else f[i][j]=max(f[i-1][j],f[i][j-1]);
	   }
	   cout<<f[n1][n2];
	return 0;
}
