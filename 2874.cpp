#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
#include<list>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
list<int>a[20005];
int n,m,InDg[20005],TopAns[20005];
inline int GetInt()
{
	char t;
	int num=0;
	while(t=getchar(),t>='0'&&t<='9')num=num*10+(t-'0');
	return num;
}
int main(){
	n=GetInt();
	m=GetInt();
	int x,y;
	memset(InDg,0,sizeof(InDg));
	memset(TopAns,0,sizeof(TopAns));
	for(int i=1;i<=m;i++)
	{
		x=GetInt();
		y=GetInt();
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
	if(TopAns[0]==n)for(int i=1;i<=TopAns[0];i++)printf("%d ",TopAns[i]);
	else puts("no solution");
	return 0;
}
