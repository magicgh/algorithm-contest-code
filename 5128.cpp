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
const int MAXN=300005;
vector<int>Col[MAXN];
int List[MAXN];
int n,m; 
namespace FastIO
{
	const int L=1<<15;
	char buf[L],*S,*T;
	inline char getchar()
	{
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,L,stdin);
			if(S==T)return EOF;
		}
		return *S++;
	}
	inline const int GetInt()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline void PutInt(int x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)PutInt(x/10);
	     putchar(x%10+'0');
	}
}
using FastIO::GetInt;
using FastIO::PutInt;
inline int Query(int l,int r,int c)
{
	return upper_bound(Col[c].begin(),Col[c].end(),r)-lower_bound(Col[c].begin(),Col[c].end(),l);
}
inline void Modify(int pos)
{
	*lower_bound(Col[List[pos]].begin(),Col[List[pos]].end(),pos)=pos+1;
	*lower_bound(Col[List[pos+1]].begin(),Col[List[pos+1]].end(),pos+1)=pos;
	int c1=List[pos],c2=List[pos+1];
	List[pos]=c2,List[pos+1]=c1;
}
int main()
{
	n=GetInt(),m=GetInt();
	for(ri i=1;i<=n;i++)Col[List[i]=GetInt()].push_back(i);
	for(ri i=1;i<=m;i++)
	{
		int op=GetInt();
		if(op==1)
		{
			int l=GetInt(),r=GetInt(),c=GetInt();
			PutInt(Query(l,r,c)),putchar('\n');
		}
		else 
		{
			int pos=GetInt();
			if(List[pos]!=List[pos+1])Modify(pos);
		}
	}
	return 0;
}

