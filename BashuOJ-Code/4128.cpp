#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=50005;
int Mob[MAXN],p[MAXN],Sm[MAXN];
bool vst[MAXN];
int a,b,k,n;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Pretreatment()
{
	Mob[1]=1;
	for(ri i=2;i<MAXN;i++)
	{
		if(!vst[i])p[++p[0]]=i,Mob[i]=-1;
		for(ri j=1;j<=p[0]&&i*p[j]<MAXN-1;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0){Mob[i*p[j]]=0;break;}
			Mob[i*p[j]]-=Mob[i];
		}
	}
	for(ri i=1;i<MAXN;i++)Sm[i]=Sm[i-1]+Mob[i];
}
inline long long Calc(int r1,int r2)
{
	if(r1>r2)swap(r1,r2);	
	r1/=k,r2/=k;
	int i,next=0,ans=0;
	for(i=1;i<=min(r1,r2);i=next+1)
	{
		next=min(r1/(r1/i),r2/(r2/i));
		ans+=(r1/i)*(r2/i)*(Sm[next]-Sm[i-1]);
	}
	return ans;
}
int main()
{
	Pretreatment(); 
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		a=getint(),b=getint(),k=getint();
		printf("%d\n",Calc(a,b));
	}
	return 0;
}

