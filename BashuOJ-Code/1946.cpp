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
int n,m,InDg[20005],TopAns[20005],Bonus[20005],FinalAns=0;
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
	memset(Bonus,0,sizeof(Bonus));
	memset(TopAns,0,sizeof(TopAns));
	for(int i=1;i<=m;i++)
	{
		y=GetInt();
		x=GetInt();
		a[x].push_back(y);
		InDg[y]++;
	}
	for(int i=1;i<=n;i++)if(!InDg[i])q.push(i),Bonus[i]=100;
	while(!q.empty())
	{
		int x=q.top();
		q.pop();
		TopAns[++TopAns[0]]=x;
		list<int>::iterator i;
		for(i=a[x].begin();i!=a[x].end();++i)
		{
			InDg[*i]--;
			Bonus[*i]=max(Bonus[*i],Bonus[x]+1);
			if(InDg[*i]==0)q.push(*i);
		}
	}
	for(int i=1;i<=n;i++)FinalAns+=Bonus[i];
	if(TopAns[0]==n)printf("%d",FinalAns);
	else puts("Poor Xed");
	return 0;
}
