/*
ID: baymax01
PROG: dualpal
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
bool Trans(int a,int k)
{
	int num[1005],i=0;
	memset(num,0,sizeof(num));
	while(a)
	{
		num[++i]=a%k;
		a/=k;
	}
	for(int j=1;j<=i/2;j++)
    if(num[j]!=num[i-j+1])return false;
    return true;
}
int main(){
//	freopen("dualpal.in","r",stdin);
	//freopen("dualpal.out","w",stdout);
	int n,s,sum=0,js=0;
	cin>>n>>s;
	int i,j;
	for(i=s+1;js<n;i++)
	{
        sum=0;
		for(j=2;j<=10;j++)
		{
		if(Trans(i,j))sum++;
		if(sum==2)
		{
			js++;
			cout<<i<<endl;
			break;
		}
		}
	}
	return 0;
}
