#include<cstdio>
#include<algorithm>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=40005;
vector<int>a[MAXN];
int n,q,cnt,root,num[MAXN][2];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int fa)
{
	num[u][0]=++cnt;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		if(*it!=fa)DFS(*it,u);
	num[u][1]=++cnt;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int u=getint(),v=getint();
		if(v!=-1)
		{
			a[u].push_back(v);
			a[v].push_back(u);
		}
		else root=u;
	}
	DFS(root,0),q=getint();
	for(ri i=1;i<=q;i++)
	{
		int u=getint(),v=getint();
		if((num[u][0]<num[v][0])&(num[v][1]<num[u][1]))printf("1\n");
		else if((num[v][0]<num[u][0])&(num[u][1]<num[v][1]))printf("2\n");
		else printf("0\n");
	}
	return 0;
}