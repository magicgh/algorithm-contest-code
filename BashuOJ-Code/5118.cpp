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
const int MAXN=100005;
vector<int>a[MAXN];
vector<int>f[MAXN];
int n,k,cnt,Size[MAXN],dfn[MAXN],w[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u)
{
    dfn[++cnt]=u,Size[u]=1;
    vector<int>::iterator it;
    for(it=a[u].begin();it!=a[u].end();++it)
    {
        DFS(*it);
        Size[u]+=Size[*it];
    }
}
int DP(int i,int j)
{
    if(i>n)return 0;
    if(j==0)return 0;
    if(f[i][j])return f[i][j];
    f[i][j]=max(f[i][j],DP(i+Size[dfn[i]],j-1)+w[dfn[i]]);
    f[i][j]=max(f[i][j],DP(i+1,j));
    return f[i][j];
}
int main()
{
    n=GetInt(),k=GetInt()+1;
    for(ri i=2;i<=n;i++)
    {
        int fa=GetInt(),val=GetInt();
        a[fa].push_back(i);
        w[i]=val;
    }
    DFS(1);
    for(ri i=1;i<=n;i++)
        f[i].resize(k+1);
    printf("%d\n",DP(1,k));
	return 0;
}


