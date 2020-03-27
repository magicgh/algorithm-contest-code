#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAXN=700005;
int N,M,cnt=0,FinalAns=0;
int val[20000005],root[20000005],s[20000005],S[20000005],ch[20000005][2];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int Build(int now,int val)
{
	int next=++cnt,order=next;
	for(int i=27;i>=0;i--)
	{
	ch[next][0]=ch[now][0];
	ch[next][1]=ch[now][1];
	s[next]=s[now]+1;
	int t=(val>>i)&1;
	now=ch[now][t];
	ch[next][t]=++cnt;
	next=ch[next][t];
	}
	s[next]=s[now]+1;
	return order;
}
int Query(int x,int y,int v)
{
	int ans=0;
	for(int i=27;i>=0;i--)
	{
		int t=(v>>i)&1;
		if(s[ch[y][!t]]>s[ch[x][!t]])
		{
			x=ch[x][!t],y=ch[y][!t];
			ans+=(1<<i);
		}
		else x=ch[x][t],y=ch[y][t];
	}
	return ans;
}
int main(){
	char ch;
	N=GetInt();M=GetInt();
	N++;
	for(int i=2;i<=N;i++)val[i]=GetInt(),S[i]=S[i-1]^val[i];
	for(int i=1;i<=N;i++)root[i]=Build(root[i-1],S[i]);
	for(int i=1;i<=M;i++)
	{
		while(ch=getchar())if(ch=='A'||ch=='Q')break;
		if(ch=='A')
		{
		val[++N]=GetInt();
		S[N]=S[N-1]^val[N];
		root[N]=Build(root[N-1],S[N]);
		}
		if(ch=='Q')
		{
			int l=GetInt(),r=GetInt(),x=GetInt();
			printf("%d\n",Query(root[l-1],root[r],S[N]^x));
		}
	}
	return 0;
}
