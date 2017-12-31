	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<iomanip>
	#include<cmath>
	#include<algorithm> 
	using namespace std;
	int N,M,K,NN,T;
	long long ans;
	inline int GetInt()
	{
		int num=0,bj=1;
		char c=getchar();
		while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	struct node
	{
		int x,y;
	};
	inline bool cmp(node q,node r)
	{
		return (q.x<r.x)||(q.x==r.x&&q.y<r.y);
	}
	struct bit
	{
		int C[500005];
		inline int Lowbit(int x){return x&(-x);}
		inline void Init()
		{
		ans=0;
		memset(C,0,sizeof(C));
		}
		inline void Modify(int x,int d)
		{
		for(int i=x;i<=M;i+=Lowbit(i))C[i]+=d;
		}
		inline int Sum(int x)
		{
		int Ans=0;
		for(int i=x;i>0;i-=Lowbit(i))Ans+=C[i];
		return Ans;
		}
	};
	bit tr;
	node data[500005];
	int main(){
		int cnt=0;	
		T=GetInt();
		for(int i=1;i<=T;i++)
		{	
			N=GetInt();
			M=GetInt();
			K=GetInt();
			tr.Init();
			memset(data,0,sizeof(data));	
			for(int j=1;j<=K;j++)
			{
				int x,y;
				x=GetInt();
				y=GetInt();
				data[j]=(node){x,y};
			}
			sort(data+1,data+K+1,cmp);
			for(int j=1;j<=K;j++)
			{	
				ans+=tr.Sum(M)-tr.Sum(data[j].y);
				tr.Modify(data[j].y,1);
			}
			printf("Test case %d: %lld\n",++cnt,ans);	
		}
		return 0;			
	}
