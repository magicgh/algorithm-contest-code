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
char a[MAXN],b[MAXN];
int last,root,cnt;
int prt[MAXN<<1],len[MAXN<<1],Right[MAXN<<1],ch[MAXN<<1][30];
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
	prt[cnt]=Right[cnt]=0;
	len[cnt]=val;
	memset(ch[cnt],0,sizeof(ch[cnt]));//清零
	return cnt;
}
void Insert(int x)
{
	int p=last,now=newnode(len[last]+1);
	last=now;//新建节点并更新last
	for(;p&&!ch[p][x];p=prt[p])ch[p][x]=now;//给所有的存在节点添加新儿子now
	if(!p)prt[now]=root;//此时的p为第一个节点,p为root直接加 
	else
	{
		int q=ch[p][x];
		if(len[q]==len[p]+1)//p,q之间无中间点,q由p访问到
			prt[now]=q;//对于now的prt,p与q点等效
		else//p,q之间有中间点,不能直接访问到 
		{
			int nq=newnode(len[p]+1);//建立一个q的等效节点nq
			for(ri i=1;i<=26;i++)ch[nq][i]=ch[q][i];
			prt[nq]=prt[q];
			prt[now]=prt[q]=nq;//转移并更新q与nq之间的关系
			for(;p&&ch[p][x]==q;p=prt[p])ch[p][x]=nq;//更新p与nq之间的关系 
		} 
	}
}
void Build(char *s)
{
	int n=strlen(s+1);
	for(ri i=1;i<=n;i++)Insert(int(s[i]-96));
}
int match(char *s)
{
	int n=strlen(s+1);
	int ans=0,slen=0,p=root;
	for(ri i=1;i<=n;i++)
	{
		int x=int(s[i]-96);
		if(ch[p][x])p=ch[p][x],slen++;
		else
		{
			while(p&&!ch[p][x])p=prt[p];
			if(!p)slen=0,p=root;
			else slen=len[p]+1,p=ch[p][x];
		}
		ans=max(ans,slen);
	}
	return ans;
}
int main()
{
	scanf("%s%s",a+1,b+1);
	root=last=newnode(0);//初始化 
	Build(a);
	printf("%d",match(b)); 
	return 0;
}

