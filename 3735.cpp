#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long N,Q;
long long Ans=0;
inline long long GetInt()
{
	long long num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
long long s[100005];
struct bit
{
	long long C[100005];
	inline long long Lowbit(long long x){return x&(-x);}
	inline void Init()
	{
	Ans=0;
	memset(C,0,sizeof(C));
	}
	inline void Modify(long long x,long long d)
	{
	for(int i=x;i<=N;i+=Lowbit(i))C[i]+=d;
	}
	inline long long Sum(long long x)
	{
	long long Ans=0;
	for(int i=x;i>0;i-=Lowbit(i))Ans+=C[i];
	return Ans;
	}
};
bit tr,delta;//delta为加入增量 
int main(){
	N=GetInt();
	Q=GetInt();
	char ch;
	for(int i=1;i<=N;i++)s[i]=s[i-1]+GetInt();//初始化前缀和
	int x,y,z;
	for(int i=1;i<=Q;i++)
	{
		scanf("%s",&ch);
		if(ch=='C')
		{
			x=GetInt();
			y=GetInt();
			z=GetInt();
			tr.Modify(x,z);
			tr.Modify(y+1,-z);
			delta.Modify(x,z*x);
			delta.Modify(y+1,-z*(y+1));
		}
		if(ch=='Q')
		{	
			x=GetInt();
			y=GetInt();
			Ans=s[y]-s[x-1]+(y+1)*tr.Sum(y)-x*tr.Sum(x-1)-delta.Sum(y)+delta.Sum(x-1);
			printf("%lld\n",Ans);
		}
	} 
	return 0;
}
