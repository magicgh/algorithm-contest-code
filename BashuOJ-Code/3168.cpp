#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=1000005;
char str[MAXN];
int ch[MAXN][30],fail[MAXN],Cnt[MAXN];
int T,N,cnt=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Insert(char *s)
{
	int u=0,len=strlen(s+1);
	for(ri i=1;i<=len;i++)
	{
		int v=s[i]-'a'+1;
		if(!ch[u][v])
			ch[u][v]=++cnt;
		u=ch[u][v];
	}
	Cnt[u]++;
}
inline void Build(int v0)
{
	queue<int>q;
	q.push(v0);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(ri v=1;v<=26;v++)
		{
			if(ch[u][v])
			{
				if(u)fail[ch[u][v]]=ch[fail[u]][v];
				q.push(ch[u][v]);
			}
			else ch[u][v]=ch[fail[u]][v];
		}
	}
}
inline int Query(char *s)
{
	int u=0,len=strlen(s+1),ret=0;
	for(ri i=1;i<=len;i++)
	{
		int v=s[i]-'a'+1,x=ch[u][v];
		while(x)
		{
			ret+=Cnt[x];
			Cnt[x]=0;
			x=fail[x];
		}
		u=ch[u][v];
	}
	return ret;
}
int main()
{
	T=GetInt();
	while(T--)
	{
		N=GetInt(),cnt=0;
		memset(fail,0,sizeof(fail));
		memset(ch,0,sizeof(ch));
		memset(Cnt,0,sizeof(Cnt));
		for(ri i=1;i<=N;i++)
		{
			scanf("%s",str+1);
			Insert(str);
		}
		Build(0);
		scanf("%s",str+1);
		printf("%d\n",Query(str));
	}
	return 0;
}
