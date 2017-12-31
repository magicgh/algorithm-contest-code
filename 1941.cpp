#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
int n,m;
struct node
{
	int ai,bi,ci,value,key;
};
bool operator<(node a,node b)
{
	return a.value>b.value;
}
priority_queue<node>q;
int main(){
	int x,y,z;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		q.push((node){x,y,z,x+y+z,1});
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",q.top().value);
	    int a=q.top().ai,b=q.top().bi,c=q.top().ci,v=q.top().value,k=q.top().key;
	    q.pop();
	    q.push((node){a,b,c,a*(k+1)*(k+1)+b*(k+1)+c,k+1});
	}
	return 0;
}
