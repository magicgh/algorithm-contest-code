#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define f for(i=1;i<=80005;i++)
using namespace std;
int a[10005]={0},b[10005]={0},fa[80005]={0},fb[80005]={0};
int main(){
	
	int n,m,i;
	cin>>n;
	for(i=1;i<=n;i++){cin>>a[i];fa[a[i]+40000]=1;}
	cin>>m;
	for(i=1;i<=m;i++){cin>>b[i];fb[b[i]+40000]=1;} 
	bool js=0;
	f
	{
		if(fa[i]&&fb[i])
		{
			cout<<i-40000<<' ';js=1;
		}
	}
	if(js==0)cout<<"nil";
	cout<<endl; 
	js=0;
	f
	{
		if(fa[i]||fb[i])
		{
			cout<<i-40000<<' ';js=1;
		}
	}
	if(js==0)cout<<"nil";
	cout<<endl; 
	f
	{
		if(fa[i]&&(!fb[i]))
		{
			cout<<i-40000<<' ';js=1;
		}
	}
	if(js==0)cout<<"nil";
	cout<<endl; 
	return 0;
}
