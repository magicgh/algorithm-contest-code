#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
string s;
int a[1005]={0};
inline void Div()
{
	int d=0;
	for(int i=a[0];i>=1;i--)
	{
	a[i]+=(s[a[0]-i]-'0')+d*10;
	d=a[i]%2;
	a[i]/=2;
	}
	while(a[0]>1&&a[a[0]]==0)a[0]--;
}
inline void Minus(int x)
{
	a[1]-=x;
	for(int i=1;i<=a[0];i++)if(a[i]<0)a[i+1]--,a[i]+=10;
}
int main(){
	cin>>s;
	a[0]=s.length();
	int t=0;
	if(a[0]==1)t=a[a[0]-1];
	else t=(s[a[0]-1]-'0')+(s[a[0]-2]-'0')*10;
	if(t%2==1)a[1]--,Div();
	else if(t%4==0)Div(),Minus(1);
	else Div(),Minus(2);
	for(int i=a[0];i>=1;i--)cout<<a[i];
	return 0;
}
