#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm> 
using namespace std;
int N,NN;
long long Ans;
int a[500005],b[500005];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}	
struct bit
{
	int C[500005];
	inline int Lowbit(int x){return x&(-x);}
	inline void Init()
	{
	NN=0,Ans=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(C,0,sizeof(C));
	}
	inline void Modify(int x,int d)
	{
	for(int i=x;i<=N;i+=Lowbit(i))C[i]+=d;
	}
	inline int Sum(int x)
	{
	int Ans=0;
	for(int i=x;i>0;i-=Lowbit(i))Ans+=C[i];
	return Ans;
	}
};
bit tr;
int main(){
	while(N=GetInt(),N!=0)
	{
		tr.Init();
		for(int i=1;i<=N;i++)a[i]=b[i]=GetInt();
		sort(b+1,b+N+1,greater<int>()); 
		NN=unique(b+1,b+N+1)-(b+1);
		for(int i=1;i<=N;i++)
		{
			a[i]=lower_bound(b+1,b+NN+1,a[i],greater<int>())-b;
			tr.Modify(a[i],1);
			Ans+=tr.Sum(a[i])-1;
		}
		printf("%lld\n",Ans);	
	}
	return 0;
}
