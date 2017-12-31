#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=2005;
vector<int>a[MAXN];
int n,m,k,Ans;
int SG[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u)
{
	if(SG[u]!=-1)return;
	bool used[MAXN];
	memset(used,0,sizeof(used));
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		DFS(*it);
		used[SG[*it]]=1;
	}
	for(ri i=0;;i++)
		if(!used[i]){SG[u]=i;break;}
}
int main()
{
	n=getint(),m=getint(),k=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back(y);
	}
	memset(SG,-1,sizeof(SG)); 
	for(ri i=1;i<=n;i++)
		if(SG[i]==-1)DFS(i);
	for(ri i=1;i<=k;i++)
		Ans^=SG[getint()];
	if(Ans)printf("win\n");
	else printf("lose\n");
	return 0;
}

