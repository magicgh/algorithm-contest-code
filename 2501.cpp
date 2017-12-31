#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=65540;
int n,a[MAXN],b[MAXN],cnt;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u)
{
	if(u>n)return;
	b[u]=a[++cnt];
	DFS(u<<1|1),DFS(u<<1);
}
int main()
{
	n=getint();
	for(int i=1;i<=n;i++)a[i]=getint();
	sort(a+1,a+n+1);
	DFS(1);
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}

