#include<iostream>
using namespace std;
int n,m,x,y,i,j,js,maxn=-10000,mr=0,a[100005]={0},root;
int main(){
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[y]=x;
	}
	for(i=1;i<=n;i++)
	{
	
	if(a[i]==0)root=i;
	}
	for(i=1;i<=n;i++)
	{
	js=0;
	for(j=1;j<=n;j++)
	{
		if(a[j]==i)js++;	
	}
   if(js>maxn)
	{
		maxn=js;
		mr=i;
	}	
	}
	cout<<root<<endl<<mr<<endl;
	for(i=1;i<=n;i++)if(a[i]==mr)cout<<i<<' ';
	return 0;
}
