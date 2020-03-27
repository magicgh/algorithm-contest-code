#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
string a;
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a;
	int str=a.length();
	for(int j=0;j<str;j++)
	{
		if(a[j]=='$')
		{
			int k=j;
			while(a[k]=='$'||a[k]=='0')k--;
			a[j]=a[k]='0';
				
		}
		if(a[j]=='#')for(int k=0;k<=j;k++)a[k]='0';
	}
	for(int m=0;m<str;m++)if(a[m]!='0')cout<<a[m];
	cout<<endl;
	}
	return 0;
}
