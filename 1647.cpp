#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
int t,n,t1,t2;
int main(){
	priority_queue<int, vector<int>, greater<int> >qmax;
	priority_queue<int, vector<int>, less<int> >qmin;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		qmax.push(t);
		qmin.push(t);
	}
	for(int i=1;i<n;i++)
	{
		t1=qmax.top();
		qmax.pop();
		t2=qmax.top();
		qmax.pop();
		qmax.push(t1*t2+1);
		t1=qmin.top();
		qmin.pop();
		t2=qmin.top();
		qmin.pop();
		qmin.push(t1*t2+1);
	}
	cout<<qmax.top()-qmin.top();
	return 0;
}
