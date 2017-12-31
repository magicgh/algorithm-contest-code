#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<set>
using namespace std;
long long n,m;
long long num[105]={0};
set<long long,less<long long> >s;
inline long long GetInt()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	int i,j;
	n=GetInt();
	m=GetInt();
	s.insert(1);
	for(i=1;i<=n;i++)num[i]=GetInt();
	for(i=1;i<=m;i++)
	{
		int k=*s.begin();
		s.erase(k);
		for(j=1;j<=n;j++)if(s.size()<m*3.5&&(k*num[j]>0))s.insert(k*num[j]);
		//迷之优化 
	}
	printf("%lld",*s.begin());
	return 0;
}