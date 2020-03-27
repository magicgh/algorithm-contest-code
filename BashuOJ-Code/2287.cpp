#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
struct heap
{
	int u;double val;
	bool operator < (const heap &rhs)const{return val>rhs.val;}
};
priority_queue<heap>q;
int n,m,a[200005],ch[400005][2],order=200004,v[400005];
double ans,fre[200005],sum;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	}
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u)
{
	if(!u)return;
	v[ch[u][0]]=v[u]+1;
	v[ch[u][1]]=v[u]+1;
	DFS(ch[u][0]);DFS(ch[u][1]);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)a[i]=getint(),sum+=a[i];
	for(ri i=1;i<=n;i++)fre[i]=a[i]/sum,q.push((heap){i,fre[i]});
	while(!q.empty())
	{
		heap op1=q.top();q.pop();
		heap op2=q.top();q.pop();
		if(op1.u==op2.u)break;
		ch[++order][0]=op1.u;
		ch[order][1]=op2.u;
		heap newnode=(heap){order,op1.val+op2.val};
		q.push(newnode);
	}
	DFS(order);
	for(ri i=1;i<=n;i++)ans+=v[i]*fre[i];
	printf("%.6lf",ans);
	return 0;
}

