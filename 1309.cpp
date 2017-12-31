/*
ID: baymax01
PROG: text
LANG: C++                  
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <cassert>
#include <cctype>
#include <queue>
using namespace std;
int degree[1005],n,a[1005],sum=0;
bool map[105][105],bj=0;
bool Topsort()
{
	for(int i=1;i<=n;i++)
	{
		int j=1;
		while(j<=n&&degree[j])j++;
		if(j>n)return false;
			a[++sum]=j;
			degree[j]=-1;
			for(int k=1;k<=n;k++)if(map[j][k])degree[k]--;
	}
return true;
}
int main()
{
memset(map,0,sizeof(map));
memset(degree,0,sizeof(degree));
int x,y;
cin>>n;
while(cin>>x>>y)
{
map[x][y]=1;
degree[y]++;
}
if(Topsort())
for(int i=1;i<=sum;i++)cout<<a[i]<<' ';
else cout<<"No answer";
return 0;
}