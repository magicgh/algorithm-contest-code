#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue> 
int n,k,t;
using namespace std;
int main(){
	priority_queue<int, vector<int>, greater<int> >q;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>t,q.push(t);
	for(int i=1;i<=k;i++)
	{
		q.push(2*q.top());
		q.pop();
	}
	for(int i=1;i<=n;i++)
	{
		t=q.top();
		q.pop();
		cout<<t<<' ';
	}
	return 0;
}
