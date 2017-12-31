#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
int n,m,Max=1;
int prt[MAXN],cnt[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int Getfa(int x)
{
	if(prt[x]==x)return x;
	return prt[x]=Getfa(prt[x]);
}
void Union(int x,int y)
{
	int f1=Getfa(x),f2=Getfa(y);
	if(f1!=f2)prt[f1]=f2,cnt[f1]=cnt[f2]=cnt[f1]+cnt[f2],Max=max(Max,cnt[f1]);
}
int main()
{
	n=GetInt();
	m=GetInt();
	for(int i=1;i<=n;i++)prt[i]=i,cnt[i]=1;
	for(int i=1;i<=m;i++)
	{
		int k=GetInt();
		if(k==1)Union(GetInt(),GetInt());
		if(k==2)printf("%d\n",Max);
	}
 return 0;
}
