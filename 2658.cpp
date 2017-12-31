#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath> 
using namespace std;
int M,N,T;
int C[1005][1005];
inline int Lowbit(int x){return x&(-x);}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Modify(int x,int y,int d)//累加 记录反转的次数 
{
	for(int i=x;i<=N;i+=Lowbit(i))
	for(int j=y;j<=N;j+=Lowbit(j))C[i][j]+=d;
}
inline int Sum(int x,int y)
{
	int Ans=0;
	for(int i=x;i>0;i-=Lowbit(i))
	for(int j=y;j>0;j-=Lowbit(j))Ans+=C[i][j];
	return Ans;
} 
int main(){
	char ch;
	int a,b,c,d;
	T=GetInt();
	for(int i=1;i<=T;i++)
	{
	memset(C,0,sizeof(C)); 
	N=GetInt();
	M=GetInt();
	for(int j=1;j<=M;j++)
	{
		scanf("%s",&ch);
		if(ch=='C')
		{
			a=GetInt();
			b=GetInt();
			c=GetInt();
			d=GetInt();
			Modify(a,b,1);
			Modify(a,d+1,1);
			Modify(c+1,b,1);
			Modify(c+1,d+1,1);//对于矩形的四个顶点的区间进行反转 
			//三个区间 [a,b]->([a,d],[c,b],[c,d]) 
			 
		}
		if(ch=='Q')
		{
			a=GetInt();
			b=GetInt();
			printf("%d\n",Sum(a,b)&1);//次数为奇(1) 次数为偶(0) 
		}
	}
		printf("\n");
	}
	return 0;
}