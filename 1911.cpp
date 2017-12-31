#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
int n,k,m,t,ans=0;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		q.push(t);
	}
	t=0;
	m=n%(k-1);
	if(m==0)m=k-1;
	if(m==1)m=k;
	for(int i=1;i<=m;i++)t+=q.top(),q.pop();
	q.push(t);
	ans+=t;
	while(q.size()!=1)
	{
		t=0;
		for(int i=1;i<=k;i++)
		{
			t+=q.top();
			q.pop();
		}
		q.push(t);
		ans+=t;
	}
	printf("%d",ans);
	return 0;
}
