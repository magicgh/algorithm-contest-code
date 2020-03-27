#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;
vector<int>a[200005];
int s[200005];
bool vst[200005];
int N,ans=0x7fffffff,ansN=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int x,int fa)
{
	int Max=-0x7fffffff;
	vector<int>::iterator it;
	s[x]=1;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(*it!=fa&&!vst[*it])
		{
		DFS(*it,x);
		s[x]+=s[*it];
		Max=max(Max,s[*it]);
	}
	}
	Max=max(Max,N-s[x]);
	if(ans>Max)ans=Max,ansN=x;
}
int main(){
	N=GetInt();
	for(int i=1;i<N;i++)
	{
		int x=GetInt(),y=GetInt();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFS(1,0);
	printf("%d %d",ansN,ans);
	return 0;
}
