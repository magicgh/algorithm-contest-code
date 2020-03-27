#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<set> 
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
int T,n,m,prt[1005];
set<int>s;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
inline void Merge(int x,int y)
{
	int f1=getfa(x),f2=getfa(y);
	if(f1!=f2)prt[f1]=f2;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	T=GetInt();
	while(T--)
	{
		n=GetInt(),m=GetInt();
		for(ri i=1;i<=n;i++)prt[i]=i;
		s.clear();
		for(ri i=1;i<=m;i++)
		{
			int x=GetInt(),y=GetInt();
			Merge(x,y);
		} 
		for(ri i=1;i<=n;i++)s.insert(getfa(i));
		cout<<s.size()<<endl;
	}	
	//fclose(stdin);
    //fclose(stdout);
    return 0;
}
