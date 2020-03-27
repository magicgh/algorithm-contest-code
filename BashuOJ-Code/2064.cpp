/*
ID: magicgh
PROG: palsquare
LANG: C++                  
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int str1,a[1005],b[1005];
void Output(int m,int n)
{
	int j=0;
		while(m)
    {
	b[++j]=m%n;
    m=m/n;
    }
    for(int i=j;i>=1;i--)
    {
	if(b[i]>=10)cout<<char(65+b[i]-10);
	else cout<<b[i];
	}
    cout<<' ';
	for(int i=1;i<=str1;i++)
	{
	if(a[i]>=10)cout<<char(65+a[i]-10);	
	else cout<<a[i];
	}
	return;
}
bool Trans(int m,int n)
{
	int  i=0;
	memset(a,0,sizeof(a));
	while(m)
    {
	a[++i]=m%n;
       m=m/n;
    }
    str1=i;
    for(int j=1;j<=i/2;j++)
    if(a[j]!=a[i-j+1])return false;
    return true;
}
int main(){
	//freopen("palsquare.in","r",stdin);
    //freopen("palsquare.out","w",stdout);
	int b;
	cin>>b;
	for(int i=1;i<=300;i++){if(Trans(i*i,b)){
	Output(i,b);cout<<endl;}}
	return 0;
}