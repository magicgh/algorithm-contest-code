#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long N,Max=-1e100,Maxn=-1e100;//Max记录最大的积，Maxn记录最大的因数个数 
int Prime[]={0,2,3,5,7,11,13,17,19,23,29,31,33,37,39};
//剪枝1：质因数的个数最多为10个 
inline long long GetInt()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
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
int main(){
	N=GetInt();
	DFS(1,1,31,1);//DFS(目前的积,因数个数,最大递归量,质数位置) 
	printf("%lld",Max);
	return 0;
}