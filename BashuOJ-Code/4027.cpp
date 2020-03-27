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
const int MAXN=250005;
char a[MAXN];
int prt[MAXN<<1],ch[MAXN<<1][30],len[MAXN<<1],Right[MAXN<<1],tong[MAXN<<1],Top[MAXN<<1],f[MAXN<<1];
int cnt,root,last;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int newnode(int val)
{
	cnt++;
	prt[cnt]=0,len[cnt]=val;
	return cnt;
}
inline void Insert(int x)
{
	int p=last,now=newnode(len[last]+1);
	last=now;
	for(;p&&!ch[p][x];p=prt[p])ch[p][x]=now;
	if(!p)prt[now]=root;
	else
	{
		int q=ch[p][x];
		if(len[q]==len[p]+1)prt[now]=q;
		else
		{
			int nq=newnode(len[p]+1);
			for(ri i=1;i<=26;i++)ch[nq][i]=ch[q][i];
			prt[nq]=prt[q];
			prt[now]=prt[q]=nq;
			for(;p&&ch[p][x]==q;p=prt[p])ch[p][x]=nq;
		}
	}
}
void Build(char *s)
{
	root=last=newnode(0);
	int n=strlen(s+1);
	for(ri i=1;i<=n;i++)Insert(int(s[i]-96));
}
int main()
{
	scanf("%s",a+1);
	Build(a);
	int n=strlen(a+1);
	for(ri i=1,p=root;i<=n;i++)
		p=ch[p][int(a[i]-96)],Right[p]++;//获取Right[]
	//搞拓扑序
	for(ri i=1;i<=cnt;i++)tong[len[i]]++;
	for(ri i=1;i<=n;i++)tong[i]+=tong[i-1];
	for(ri i=1;i<=cnt;i++)Top[tong[len[i]]--]=i;
	for(ri i=cnt;i>=1;i--)Right[prt[Top[i]]]+=Right[Top[i]];//自下而上的累加Right[]
	for(ri i=1;i<=cnt;i++)f[len[i]]=max(f[len[i]],Right[i]);//用Right[]更新f[]的值
	for(ri i=n;i>=1;i--)f[i]=max(f[i+1],f[i]);//用f[i+1]更新f[i]的值
	for(ri i=1;i<=n;i++)printf("%d\n",f[i]);//从所有f[]找最大值 
	return 0;
}
