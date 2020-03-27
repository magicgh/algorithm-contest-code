#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int n,k;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		q.push(k);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",q.top());
		q.pop();
	}
	return 0;
}
