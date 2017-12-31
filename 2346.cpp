#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
int N,ans[20]={0};
bool used[20]={0},Prime[25]={0},Flag=0;
inline void DFS(int k)
{
	if(k==N+1&&Prime[ans[1]+ans[k-1]])
	{
		for(int i=1;i<=N;i++)printf("%d ",ans[i]);
		Flag=1;
		putchar('\n');
	}
	else for(int i=1;i<=N;i++)
	{
		if(!used[i]&&(k==1||Prime[ans[k-1]+i]))
		{
			ans[k]=i,used[i]=1,DFS(k+1);used[i]=0;
		}
	}
}
int main()
{
N=GetInt();
Prime[2]=Prime[3]=Prime[5]=Prime[7]=Prime[11]=Prime[13]=Prime[17]=Prime[19]=Prime[23]=1;
DFS(1);
if(!Flag)puts("NO");
return 0;
}
