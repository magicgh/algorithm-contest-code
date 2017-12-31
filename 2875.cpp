#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,m,i,j,k,a,b,C[205][205]={0};
int main(){
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		C[a][b]=1;
	} 
	cin>>k;
	j=0;
	for(i=1;i<=n;i++)
	if(C[k][i])j++;
	cout<<j;
	return 0;
}