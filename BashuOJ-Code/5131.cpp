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
const int MAXN=40005;
const int MAXK=20;//差分后为2k 
const int MAXM=70;
const int MAXS=65540;//差分后为2k 
const int INF=0x7fffffff/2;
struct Pair{int id,pos;};
Pair bit[MAXK];
int n,k,m,cnt;
int a[MAXN],b[MAXM],dist[MAXK][MAXN],f[MAXS];
bool vst[MAXN];
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline const int GetInt()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
};
using FastIO::GetInt;
void BFS(const Pair &s)//求出第s.id的点移到任意位置的代价 
{
	std::queue<int>q;
	q.push(s.pos);
	memset(vst,0,sizeof(vst));
	dist[s.id][s.pos]=0,vst[s.pos]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(ri i=1;i<=m;i++)
		{
			if(now-b[i]>=0&&!vst[now-b[i]])
			{
				vst[now-b[i]]=1;
				dist[s.id][now-b[i]]=dist[s.id][now]+1;
				q.push(now-b[i]);
			}
			if(now+b[i]<=n&&!vst[now+b[i]])
			{
				vst[now+b[i]]=1;
				dist[s.id][now+b[i]]=dist[s.id][now]+1;
				q.push(now+b[i]);
			}
		}
	}
}
int main()
{
	n=GetInt(),k=GetInt(),m=GetInt();
	for(ri i=1;i<=k;i++)a[GetInt()]=1;
	for(ri i=1;i<=m;i++)b[i]=GetInt();
	for(ri i=0;i<=n;i++)
	{
		a[i]^=a[i+1];
		if(a[i])bit[++cnt]=(Pair){cnt,i};
	}
	memset(dist,0x3f,sizeof(dist));
	for(ri i=1;i<=cnt;i++)BFS(bit[i]);
	for(ri s=1,i,j;s<(1<<cnt);s++)//0状态非法 
	{
		f[s]=INF;
		for(i=cnt;i>=1;i--)
			if(s&(1<<(i-1)))break;
		for(j=i-1;j>=1;j--)
			if(s&(1<<(j-1)))f[s]=std::min(f[s],f[s^(1<<(i-1))^(1<<(j-1))]+dist[i][bit[j].pos]);//注意 (1<<(i-1)) 100000...  检测第i为是否为1 
		//计算由i移动到pos的代价
	}
	//DP求出所有点都点亮的最小的代价  
	printf("%d\n",f[(1<<cnt)-1]);
	return 0;
}


