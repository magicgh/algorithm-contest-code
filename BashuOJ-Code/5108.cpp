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
const int MAXN=1005;
char s1[MAXN],s2[MAXN];
int Pair[30];
int T,l1,l2;
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int toc(const char &x){return int(x-'a'+1);}
inline bool Check(const char &x)
{
	if(isalnum(x)||x==' '||x==';')return 1;
	else return 0;
}
inline void Read()
{
	l1=l2=0;
	char ch=getchar();
	while(!Check(ch))ch=getchar();
	while(Check(ch))s1[++l1]=ch,ch=getchar();
	while(!Check(ch))ch=getchar();
	while(Check(ch))s2[++l2]=ch,ch=getchar();
}
int main()
{
	T=GetInt();
	while(T--)
	{
		Read();
		bool Flag=0,dif=0,T=0;
		if(l1!=l2){printf("0\n");continue;}
		memset(Pair,0,sizeof(Pair));
		for(ri i=1;i<=l1;i++)if(s1[i]!=s2[i]){T=1;break;}
		if(!T){printf("1\n");continue;}
		for(ri i=1;i<=l1;i++)
		{
			if(islower(s1[i])&&islower(s2[i]))
			{
				if(s1[i]==s2[i])continue;
				if(!Pair[toc(s1[i])])Pair[toc(s1[i])]=toc(s2[i]);
				else if(Pair[toc(s1[i])]!=toc(s2[i])){Flag=1;break;}
			}
			else if(s1[i]!=s2[i]){dif=1;break;}
		}
		if(dif)printf("0\n");
		else printf((Flag)?"0\n":"1\n");
	}
	return 0;
}

