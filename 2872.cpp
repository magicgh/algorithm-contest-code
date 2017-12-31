#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
struct node
{
	int E,F;
}Prt[1005];
int m,n,ans,x,y;
int GetFather(int u)
{
	if(Prt[u].F==u)return u;
	Prt[u].F=GetFather(Prt[u].F);
	return Prt[u].F;
}
void Union(int x,int y)
{
	int root_x=GetFather(x);
	int root_y=GetFather(y);
	if(root_x!=root_y)Prt[root_x].F=root_y,ans--;
	return;
}
int main(){
	cin>>n>>m;
	ans=n;
	for(int i=1;i<=n;i++)Prt[i].F=i,Prt[i].E=0;
	char t;
	for(int i=1;i<=m;i++)
	{
		cin>>t>>x>>y;
		if(t=='F')Union(x,y);
		if(t=='E')
		{
			if(Prt[x].E)Union(Prt[x].E,y);
			else Prt[x].E=y;
			if(Prt[y].E)Union(Prt[y].E,x);
			else Prt[y].E=x;
			
		}
	}
	cout<<ans;
	return 0;
}
