#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=20;
const ll Mod=998244353;
vector<int>Stu[MAXN];
vector<int>Path[MAXN];
int n,m,rs,rt,stus,stut,sum;
int Bin[MAXN];
bool Ban[MAXN],vst[MAXN],Hate[MAXN][MAXN];
ll Ans,f[MAXN][MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int fa)
{
	vst[u]=1;
	vector<int>::iterator it;
	for(it=Path[u].begin();it!=Path[u].end();++it)
	{
		if(*it==fa)continue;
		if(vst[*it])rt=*it,rs=u;
		else DFS(*it,u);
	}
}
void Tree_DP(int u,int fa)
{
	vector<int>::iterator it;
	for(it=Path[u].begin();it!=Path[u].end();++it)//遍历所有学校 
	{
		if(*it==fa)continue;
		if((u==rs&&*it==rt)||(u==rt&&*it==rs))continue;
		Tree_DP(*it,u);
	}
	vector<int>::iterator it1;
	for(it1=Stu[u].begin();it1!=Stu[u].end();++it1)//遍历该学校的学生 
	{
		int stus=*it1;
		f[u][stus]=0;//方案数清零 
		if(Ban[stus])continue;//不合法的情况
		if(u==rs&&Hate[stus][stut])continue;//断边处不合法 
		f[u][stus]=1;//rs可与stus匹配
		vector<int>::iterator it2;
		for(it2=Path[u].begin();it2!=Path[u].end();++it2)//遍历其他相邻学校 
		{
			int Near=*it2;
			if(Near==fa)continue;
			if((u==rs&&Near==rt)||(u==rt&&Near==rs))continue;
			ll tmp=0;
			vector<int>::iterator it3;
			for(it3=Stu[Near].begin();it3!=Stu[Near].end();++it3)//遍历相邻学校的学生
			{
				int student=*it3;
				if(Hate[stus][student]||Ban[student])continue;
				tmp=(tmp+f[Near][student])%Mod;
			}
			f[u][stus]=f[u][stus]*tmp%Mod;
		}
	}
}
inline ll Calc()
{
	ll cnt=0;
	vector<int>::iterator it;
	for(it=Stu[rt].begin();it!=Stu[rt].end();++it)//学校选学生 
	{
		stut=*it;
		if(Ban[stut])continue;//不能选
		Tree_DP(rt,0);
		cnt=(cnt+f[rt][stut])%Mod;
		//统计rt学校匹配学生(可能被重复选)的方案数 
	}
	return cnt;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		int k=getint();
		for(ri j=1;j<=k;j++)
			Stu[i].push_back(getint());
		Bin[i]=1<<(i-1);
	}
	for(ri i=1;i<=n;i++)
	{
		int u=getint(),v=getint();
		Path[u].push_back(v);
		Path[v].push_back(u);
	}
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();
		Hate[u][v]=Hate[v][u]=1;
	}
	DFS(1,0);	
	for(int sta=0;sta<=(1<<n)-1;sta++)
	{
		sum=0;	
		for(ri i=1;i<=n;i++)
		sum+=(Ban[i]=(sta&Bin[i])>0);//统计被Ban的人数
			Ans=(Ans+Calc()*((sum&1)?-1:1))%Mod;//容斥原理 
	}
	printf("%lld\n",(Ans%Mod+Mod)%Mod);
	return 0;
}