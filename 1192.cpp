#include<iostream>
using namespace std;
int n,h=0,w=0,a[1005]={0},b[1005]={0};
void dfs(int root,int deep)
{
	int i;
	if(deep>h)h=deep;
	for(i=1;i<=n;i++)
	{
		if(a[i]==root)
		{
			b[deep+1]++;
			dfs(i,deep+1);
		}
	}
	return;
}
int main(){
	int x,y,root,i;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		a[x]=y;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==0){root=i;break;}
	
	}
	b[1]=1;
	dfs(root,1);
	for(i=1;i<=n;i++)if(b[i]>w)w=b[i];
	cout<<h<<' '<<w;
	return 0;
}