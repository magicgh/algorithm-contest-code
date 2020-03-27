#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int a[10005]={0},n,cnt=0;
int b[10005]={0};
bool Check(int k)
{
	if(k==1)return 1;
	if(k==2)
	{
	if(a[1]==b[1]+b[2])return 1;
	else return 0;
	}
	if(a[k-1]==b[k]+b[k-1]+b[k-2])return 1;
	else return 0;
}
void dfs(int k)
{
	if(k==n+1)
	{
		if(a[n]==b[n-1]+b[n]){cnt++;return;}
	}
	else
	{
		for(int i=0;i<=1;i++)
		{
			b[k]=i;
			if(Check(k))dfs(k+1);
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<cnt;
	return 0;
}
