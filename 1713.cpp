#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>	
#define ri register int
using namespace std;
priority_queue<int, vector<int>, greater<int> >q;
int w,n,s;
int f[100005],path[100005],a[105];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int x)
{
	if(x==0)return;
	q.push(path[x]);
	DFS(x-a[path[x]]);
}
int main()
{
	w=getint(),n=getint();
	for(ri i=1;i<=n;i++)a[i]=getint(),s+=a[i];
	s-=w;
	f[0]=1;
	for(ri i=1;i<=n;i++)
	for(ri j=s;j>=a[i];j--)
	{
		if(f[j-a[i]]&&!f[j])
		{
			f[j]=f[j-a[i]];
			path[j]=i;
		}
		else if(f[j-a[i]]&&f[j])f[j]+=f[j-a[i]];
	}
	if(!f[s])printf("0\n");
	else if(f[s]>1)printf("-1\n");
	else 
	{
		DFS(s);
		while(!q.empty())printf("%d ",q.top()),q.pop();
	} 
	return 0;
}

