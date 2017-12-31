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
#define ll long long
using namespace std;
const int MAXN=500005;
priority_queue<int,vector<int>,greater<int> >q;
vector<int>a[35];
char str[1005],ch[MAXN][105];
int n,k,cnt,Deg[35],Order[35];
bool vst[35][35];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
bool Topsort()
{
	for(int i=1;i<=n;i++)if(!Deg[i])q.push(i);
	while(!q.empty())
	{
		int x=q.top();q.pop();
		Order[x]=++Order[0];
		vector<int>::iterator it;
		for(it=a[x].begin();it!=a[x].end();++it)
		{
			Deg[*it]--;
			if(Deg[*it]==0)q.push(*it);
		}
	}
	if(Order[0]==n)return 1;
	return 0;
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<=k;i++)scanf("%s",ch[i]);
	scanf("%s",str);
	for(ri i=2;i<=k;i++)
	{
		int len=min(strlen(ch[i]),strlen(ch[i-1]));
		for(ri j=0;j<len;j++)
		{
			if(ch[i][j]==ch[i-1][j])continue;
			int x=ch[i-1][j]-'a'+1,y=ch[i][j]-'a'+1;
			if(!vst[x][y])vst[x][y]=1,a[x].push_back(y);
			Deg[y]++;break;
		}
	}
	if(Topsort())
	{
		int len=strlen(str);
		for(ri i=0;i<len;i++)
			printf("%c",Order[str[i]-'a'+1]+'a'-1);
	}
	else printf("0\n");
	return 0;
}