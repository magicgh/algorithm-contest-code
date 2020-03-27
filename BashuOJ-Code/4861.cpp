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
int a,b;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Check(int x)
{
	if(x==1)return 1;
	if(x==2)return 2;
	int cnt=2;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)cnt+=(i*i==x)?1:2;
	return cnt;
}
void SolveA()
{
	int cnt=0,num=0;
	for(int x=a;x<=b;x++)
	{
		int t=Check(x);
		if(t>cnt)cnt=t,num=x;
	}
	printf("%d\n",num);
}
long long N,Max=-1e100,Maxn=-1e100;//Max记录最大的积，Maxn记录最大的因数个数 
int Prime[]={0,2,3,5,7,11,13,17,19,23,29,31,33,37,39}; 
void DFS(int ans,int cnt,int maxn,int pos)
{
	if(Maxn<cnt||(Maxn==cnt&&Max>ans))Max=ans,Maxn=cnt;//1-N内因数个数最大且数值最小 
	long long tmp=ans;//缓存临时累乘变量 
	for(int i=1;i<=maxn;i++)//剪枝2：递归层数不超过maxn,其初始值为31 
	{
		if(N/tmp<Prime[pos])break;//如果不够乘 退出循环 
		tmp*=Prime[pos];
		if(tmp<=N)DFS(tmp,cnt*(i+1),i,pos+1);//递归 
	}
	return;
}
void SolveB()
{
	N=(ll)b;
	DFS(1,1,31,1);
	printf("%lld\n",Max);	
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	a=getint(),b=getint();
	if(a<=100000&&b<=100000)SolveA();
	else SolveB();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}


