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
const int MAXN=131080;
const int Limit=131072;
int n,K,Max,tot,a[MAXN],Cnt[MAXN],List[MAXN],prt[MAXN],prv[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Getfa(int u)
{
	if(prt[u]==u)return u;
	int root=Getfa(prt[u]);
	prv[u]=(prv[u]+prv[prt[u]])%2;
	return prt[u]=root;
}
inline bool Union(int a,int b,int val)//无冲突为真 
{
	int f1=Getfa(a),f2=Getfa(b);
	if(f1==f2)return (val+prv[b]-prv[a]+2)%2==0;
	else {prt[f1]=f2;prv[f1]=(val+prv[b]-prv[a]+2)%2;return 1;}
}
inline bool is_sqr(int x)
{
	int y=sqrt(x);
	return y*y==x;
}
inline bool Check1(int num)
{
	for(ri x=2;x*x-num<=Max&&x<=512;x++)
	{
		int y=x*x-num;
		if(y<=0)continue;
		if(Cnt[y])return 0;
	}
	return 1;
}
inline bool Check2(int num)
{
	if(Cnt[num]&&is_sqr(2*num))//相同的情况 
	{
		if(Cnt[num]==2)return 0;
		//三个数相同两两之和为平方数
		for(ri x=2;x*x-num<=Max&&x<=512;x++)
		{
			int y=x*x-num;
			if(y<=0||!Cnt[y]||y==num)continue;
			//无意义或仅有两个有冲突
			else return 0;
		}
		return 1; //不冲突 
	}
	for(ri x=2;x*x-num<=Max&&x<=512;x++)
	{
		int y=x*x-num;
		if(y<=0||!Cnt[y]||y==num)continue;//无意义或仅有两个有冲突
		if(is_sqr(2*y)&&Cnt[y]==2)return 0;
		//两个相同的数且互为平方数且与num互为平方数 
		if(!Union(num,y,1))return 0;//两个有冲突，用权值并查集查找两组之间是否之间是否有冲突
		//若两组没有合并，合并后只有一对冲突，若两组合并后，多了一条有冲突的边即不合法 
	}
	return 1; 
}
void ST1()
{
	int last=n;
	for(ri i=n;i>=1;i--)
	{
		if(!Check1(a[i]))
		{
			List[++tot]=i;
			for(ri j=i+1;j<=last;j++)Cnt[a[j]]=0;
			last=i;
		}
		Cnt[a[i]]++;
	}
}
inline void Clean(int num)
{
	prt[num]=num,Cnt[num]=0;//有两个冲突则不合法，保留Cnt信息 
	for(ri x=2;x*x-num<=Max&&x<=512;x++)
	{
		int y=x*x-num;
		if(y<=0)continue;
		prt[y]=y,prv[y]=0;//删除并查集信息 
	}
}
void ST2()
{
	int last=n;
	for(ri i=1;i<=Max*2;i++)prt[i]=i;
	for(ri i=n;i>=1;i--)
	{
		if(!Check2(a[i]))
		{
			List[++tot]=i;
			for(ri j=i+1;j<=last;j++)Clean(a[j]);
			last=i;
		}
		Cnt[a[i]]++;
	}
}
int main()
{
	n=GetInt(),K=GetInt();
	for(ri i=1;i<=n;i++)a[i]=GetInt(),Max=max(a[i],Max);
	if(K==1)ST1();
	else if(K==2)ST2();
	printf("%d\n",tot+1);
	for(ri i=tot;i>=1;i--)printf("%d ",List[i]);
	return 0;
}

