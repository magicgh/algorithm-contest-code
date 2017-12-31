#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#define ri register int
using namespace std;
vector<int>w,num;
set<int>s;
int n,t;
inline int getint() {
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main() {
	t=getint();
	for(ri i=1;i<=t;i++) 
	{
		w.clear(),num.clear(),s.clear();
		int maxn=0;
		n=getint();
		for(ri j=0;j<n;j++)w.push_back(getint());
		for(ri j=0;j<n;j++)num.push_back(getint()),maxn+=w[j]*num[j];
		s.insert(maxn);
		set<int>::iterator it;
		for (int j=0;j<n;j++) 
		{
			for(it=s.begin();it!=s.end();++it) 
			{
				for(ri k=1;k<=num[j]&&*it-k*w[j]>0; k++)
					s.insert(*it-k*w[j]);
			}
		}
		s.insert(0);
		printf("%d\n",s.size());
	}
	return 0;
}
