#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int f[205][205];
int main(){
	string a,b;
	memset(f,0,sizeof(f));
	cin>>a>>b;
	int s1=a.length(),s2=b.length();
	a=' '+a,b=' '+b;
	for(int i=1;i<=max(s1,s2);i++)f[i][0]=f[0][i]=i;
	for(int i=1;i<=s1;i++)
		for(int j=1;j<=s2;j++)
		{
			if(a[i]==b[j])f[i][j]=f[i-1][j-1];
			  else f[i][j]=min(f[i-1][j]+1,min(f[i][j-1]+1,f[i-1][j-1]+1));
		}
		cout<<f[s1][s2];
	return 0;
}
