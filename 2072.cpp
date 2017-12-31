/*
ID: baymax01
PROG: ariprog
LANG: C++11              
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
bool f[130005];
int n;
bool Check(int a,int b)
{
	int i;
	for(i=0;i<n;i++)if(!f[a+i*b])return false;
	return true;
}
int main(){
	//freopen("ariprog.in","r",stdin);
	//freopen("ariprog.out","w",stdout);
	int m,i,j,t=0;
	bool flag=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<=m;i++)
	  for(j=0;j<=m;j++)f[i*i+j*j]=1;
	  int Max=2*m*m;//i=j=m,i^2+j^2=2m^2
	  for(i=1;i<=Max;i++)
	    for(j=0;j+(n-1)*i<=Max;j++)
	    {
	    	if(Check(j,i))
	    	{
	    		printf("%d %d\n",j,i);
	    		flag=1;
			}
		}
		if(flag==0)printf("NONE\n");
	return 0;
}
