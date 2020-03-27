#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{long long s,c;};
int N,K,T;
long long wlen=0,ans=0,f[20][1005][200];
node w[1005];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void DFS(int line,int now,int cnt)
{
	if(line==N){w[++wlen]=((node){now,cnt});return;}
	DFS(line+1,now<<1,cnt);
	if(!(now&1))DFS(line+1,(now<<1)|1,cnt+1);
}
inline bool Judge(int j,int l)
{
	return !(w[l].s&w[j].s)&&!(w[l].s&(w[j].s<<1))&&!(w[l].s&(w[j].s>>1));
}
void DP()
{
	memset(f,0,sizeof(f));
	f[0][1][0]=1;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=wlen;j++)
	for(int k=0;k<=K;k++)
	{
		if(k-w[j].c>=0)
		for(int l=1;l<=wlen;l++)
		if(Judge(j,l))f[i][j][k]+=f[i-1][l][k-w[j].c];
	}
}
void OutPut()
{
	for(int i=1;i<=wlen;i++)ans+=f[N][i][K];
	printf("%lld",ans);
}
int main(){
	while(~scanf("%d%d",&N,&K))
	{
	memset(f,0,sizeof(f));
	wlen=0;
	DFS(0,0,0);
	DP();
	OutPut();
}
return 0;
}
