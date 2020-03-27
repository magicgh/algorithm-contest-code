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
const int MAXN=1000005;
int n,q,block,Size;
int h[MAXN],g[MAXN],Belong[MAXN],Cache[1005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Maintain(int k)
{
	int l=(k-1)*Size+1,r=min(n,k*Size);
	for(ri i=l;i<=r;i++)
		g[i]=h[i];
	sort(g+l,g+r+1);//对于当前块进行排序 
}
inline void Add(int l,int r,int val)
{
	if(Belong[l]==Belong[r])//同一个块直接加 
	{
		for(ri i=l;i<=r;i++)h[i]+=val;
		Maintain(Belong[l]);
	}
	else//不同的块先加两边的 
	{
		for(ri i=l;i<=Belong[l]*Size;i++)h[i]+=val;
		for(ri i=(Belong[r]-1)*Size+1;i<=r;i++)h[i]+=val;
		Maintain(Belong[l]),Maintain(Belong[r]);//维护两边的块
		for(ri i=Belong[l]+1;i<Belong[r];i++)Cache[i]+=val;//缓存中间块要加的值 
	}
}
inline int Query(int l,int r,int Limit)
{
	int cnt=0;
	if(Belong[l]==Belong[r])
	{//同一个块直接求
		for(ri i=l;i<=r;i++)if(h[i]+Cache[Belong[i]]>=Limit)cnt++;
	}
	else//两边的块进行处理 
	{
		for(ri i=l;i<=Belong[l]*Size;i++)
			if(h[i]+Cache[Belong[i]]>=Limit)cnt++;
		for(ri i=(Belong[r]-1)*Size+1;i<=r;i++)
			if(h[i]+Cache[Belong[i]]>=Limit)cnt++;
		for(ri i=Belong[l]+1;i<Belong[r];i++)
			cnt+=min(i*Size,n)-(lower_bound(g+((i-1)*Size+1),g+min(i*Size,n)+1,Limit-Cache[i])-g)+1;//二分查找中间块
	}
	return cnt;
}
int main()
{
	n=getint(),q=getint();
	Size=(int)(sqrt(n));
	for(ri i=1;i<=n;i++)
	{
		h[i]=getint();
		Belong[i]=(i-1)/Size+1;
	}
	block=(n%Size)?(n/Size+1):(n/Size);
	for(ri i=1;i<=block;i++)Maintain(i);
	char ch;
	for(ri i=1;i<=q;i++)
	{
		while(ch=getchar())if(ch=='A'||ch=='M')break;
		int L=getint(),R=getint(),V=getint();
		if(ch=='M')Add(L,R,V);
		if(ch=='A')printf("%d\n",Query(L,R,V));			
	} 
	return 0;
}

