#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct highway
{
	int x,y,z,no;
}a[2005],s;
struct ans
{
	int Min,e[2005];
}b[2005];
int N,M,len=0,js=0;
bool bj=0;
int prt[2005]={0};
inline void Makitup()
{
	int i=0;
	for(i=len;i>=1;i--)if(a[i].z<=s.z)break;
	for(int j=len;j>i;j--)a[j+1]=a[j];
	a[i+1]=s;
	len++;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	prt[u]=getfa(prt[u]);
	return prt[u];
}
inline void Kruscal(int k)
{
	int ANS=0,cnt=0;bj=0;
	for(int i=1;i<=N;i++)prt[i]=i;
	for(int i=1;i<=len;i++)
	{
		int f1=getfa(a[i].x);
		int f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f1]=f2;
			cnt++;
			ANS+=a[i].z;
			b[k].e[++b[k].e[0]]=a[i].no;
			if(cnt==N-1)break;
		}
	}
	if(cnt<N-1)b[k].Min=-1;
	else b[k].Min=ANS;
	return;
}
inline void InOrder(int t[])
{
	sort(t+1,t+t[0]+1);
}
int main(){
	scanf("%d%d",&N,&M);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d%d",&s.x,&s.y,&s.z);
		s.no=i;
	    Makitup();
	    b[i].e[0]=0;
	    Kruscal(i);
	    InOrder(b[i].e);
	}
	for(int i=1;i<=M;i++)
	{
		if(b[i].Min!=-1)
		{
		printf("%0.2f ",double(b[i].Min)/2);
		for(int j=1;j<=b[i].e[0];j++)printf("%d ",b[i].e[j]);
	    }
	    else printf("0");
		printf("\n");
	}
	return 0;
}