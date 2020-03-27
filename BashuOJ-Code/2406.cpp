#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
using namespace std;
struct ppt
{
	int x1,x2,y1,y2;
};
bool Map[27][27];
bool vst[27],bj=0;
int belong[27],rec[27];
ppt a[27];
map<char,int>m;
int N,cnt=0,ans=0,NewAns=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
bool DFS(int i)
{
	for(int j=1;j<=N;j++)
	{
		if(Map[i][j]&&!vst[j])
		{
			vst[j]=1;
			if(!belong[j]||DFS(belong[j]))
			{
				belong[j]=i;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
		N=GetInt();
		for(int i=1;i<=N;i++)a[i]={GetInt(),GetInt(),GetInt(),GetInt()};
		for(int i=1;i<=N;i++)
		{
			int x=GetInt(),y=GetInt();
			for(int j=1;j<=N;j++)
				if(x>=a[j].x1&&x<=a[j].x2&&y>=a[j].y1&&y<=a[j].y2)Map[i][j]=1;
				else Map[i][j]=0;
		}
		for(int i=1;i<=N;i++)
		{
			memset(vst,0,sizeof(vst));
			if(DFS(i))ans++;
		}
		if(ans!=N)printf("None\n");
		memcpy(rec,belong,sizeof(belong));
		for(int i=1;i<=N;i++)
		{
			NewAns=0;
			memset(belong,0,sizeof(belong));
			Map[rec[i]][i]=0;
			for(int j=1;j<=N;j++)
			{
				memset(vst,0,sizeof(vst));
				if(DFS(j))NewAns++;
			}
			if(ans!=NewAns)m[char(64+i)]=rec[i];
			Map[rec[i]][i]=1;
		}
		map<char,int>::iterator it;
		for(it=m.begin();it!=m.end();++it)
		{
			if(it->second)printf("%c %d\n",it->first,it->second),bj=1;
			it->second=0;
		}
		if(!bj)printf("None\n");
 return 0;
}
