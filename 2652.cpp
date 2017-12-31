#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> >q1; 
priority_queue<int> q2;  
int N,M;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	int x;
	N=GetInt();
	for(int i=1;i<=N;i++)
	{
		M=GetInt();
		for(int j=1;j<=M;j++)
		{
			x=GetInt();
			q1.push(x);
			q2.push(x);
		}
		printf("%d %d\n",q2.top(),q1.top());
		q1.pop();q2.pop();
	}
	return 0;
}
