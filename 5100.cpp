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
stack<int>s;
vector<int>P[MAXN],M[MAXN];
int n,k; 
ll Ans,List[MAXN],sum[MAXN];
int L[MAXN],R[MAXN];
int Hash[1000005];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=GetInt(),k=GetInt();
	for(ri i=1;i<=n;i++)List[i]=GetLL(),sum[i]=(sum[i-1]+List[i])%k;
	for(ri i=1;i<=n;i++)L[i]=0,R[i]=n+1;
	for(ri i=1;i<=n;i++)//维护单增栈查找右大元素 
	{
		while(!s.empty()&&List[i]>=List[s.top()])
		{
			R[s.top()]=i;
			s.pop();
		}
		s.push(i);
	} 
	while(!s.empty())s.pop();
	for(ri i=n;i>=1;i--)//维护单增栈查找左大元素 
	{
		while(!s.empty()&&List[i]>List[s.top()])
		{
			L[s.top()]=i;
			s.pop();
		}
		s.push(i);
	 } 
	for(ri mid=1;mid<=n;mid++)
	{
		int l=L[mid],r=R[mid]-1;
		if(mid-l<r-mid)//枚举左边 
		{
			for(ri j=l+1;j<=mid;j++)
			{
				M[mid-1].push_back((List[mid]+sum[j-1])%k);//前缀减 
				P[r].push_back((List[mid]+sum[j-1])%k);//补回来 
			}
		}
		else for(ri j=mid;j<=r;j++)
		{
			if(l)M[l-1].push_back(((sum[j]-List[mid])%k+k)%k);
			P[mid-1].push_back(((sum[j]-List[mid])%k+k)%k);
		} 
	}
	for(ri i=0;i<=n;i++)
	{
		Hash[sum[i]]++;
		vector<int>::iterator v;
		for(v=M[i].begin();v!=M[i].end();++v)Ans-=Hash[*v];
		for(v=P[i].begin();v!=P[i].end();++v)Ans+=Hash[*v];
	}
	printf("%lld\n",Ans-n);
	return 0;
}


