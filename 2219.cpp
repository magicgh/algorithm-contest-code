#include<cstdio>
#include<cmath>
#define ri register int
using namespace std;
const int MAXN=45005;
int r,p[4700],Ans=1;
bool vst[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	int Limit=sqrt(r);
	for(int i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;j<=p[0]&&i*p[j]<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main()
{
	r=getint();
	Init();
	for(ri i=1;i<=p[0];i++)
	{
		int cnt=0;
		while(r%p[i]==0)
		{
			r/=p[i];
			cnt++;
		}
		if(p[i]%4!=1)continue;
		Ans*=cnt<<1|1;
	}
	if(r!=1&&r%4==1)Ans*=3;
	printf("%d\n",Ans<<2);
	return 0;
}