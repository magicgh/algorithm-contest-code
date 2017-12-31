#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int INF=0x7fffffff/2;
int N,K,W,s[100005],f[505][100005],q[100005],ans=-INF;

inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DP()
{
	int i,j,head,tail,Max;
	 for(i=2;i<=K;i++)
       for(j=head=tail=1,q[1]=0,Max=-INF;j<=N+W;j++)
		{  
		while(head<=tail&&q[head]<j-W)head++;
		if(j-W>=0)Max=max(Max,f[i-1][j-W]);
		f[i][j]=max(f[i-1][q[head]]-s[q[head]],Max-s[j-W])+s[j];
		while(head<=tail&&f[i-1][q[tail]]-s[q[tail]]<=f[i-1][j]-s[j])tail--;
		q[++tail]=j;
		ans=max(ans,f[i][j]);
		}
}
int main(){
	N=GetInt(); 
	K=GetInt(); 
	W=GetInt();
	int x;
	for(int i=1;i<=N;i++)
	{
		x=GetInt();
		s[i]=s[i-1]+x;
	}
	for(int i=N+1;i<=N+W;i++)s[i]=s[i-1];
	for(int i=1;i<=N+W;i++)f[1][i]=s[i]-s[max(i-W,0)];
	DP();
	printf("%d",ans);
	return 0;
}