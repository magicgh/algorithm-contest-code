#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
#include<list>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
list<int>a[100005];
int n,m,InDg[100005],TopAns[100005];
int main(){
	cin>>n>>m;
	int x,y;
	memset(InDg,0,sizeof(InDg));
	memset(TopAns,0,sizeof(TopAns));
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		InDg[y]++;
	}
	for(int i=1;i<=n;i++)if(!InDg[i])q.push(i);
	while(!q.empty())
	{
		int x=q.top();
		q.pop();
		TopAns[++TopAns[0]]=x;
		list<int>::iterator i;
		for(i=a[x].begin();i!=a[x].end();++i)
		{
			InDg[*i]--;
			if(InDg[*i]==0)q.push(*i);
		}
	}
	if(TopAns[0]==n)for(int i=1;i<=TopAns[0];i++)cout<<TopAns[i]<<' ';
	else puts("NO SOLUTION");
	return 0;
}
