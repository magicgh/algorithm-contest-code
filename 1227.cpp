#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<map>
using namespace std;
map<string,int>a;
int cnt[20005];
int n,m;
char s[25];
int main(){
	ios::sync_with_stdio(false);
	map<string,int>::iterator j;
	while(~scanf("%d%d",&n,&m),n!=0,m!=0)
	{
	a.clear();
	for(int i=1;i<=n;i++)scanf("%s",s),a[s]++;
	for(int i=1;i<=n;i++)cnt[i]=0;	
	for(j=a.begin();j!=a.end();++j)cnt[j->second]++;
	for(int i=1;i<=n;i++)printf("%d\n",cnt[i]);
}
	return 0;
}
