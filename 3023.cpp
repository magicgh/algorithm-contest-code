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
bool bj,used[35];
int n,fi[35],total;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int cnt,int x,int y)//模拟后续合并,检验是否可以达到n 
{
	if(x<y)swap(x,y);
	for(ri i=1;i<=cnt;i++)x+=y,y=x-y;
	return x>=n; 
}
void Output()
{
	bj=1;
	for(ri i=1;i<=total;i++)printf(used[i]?"X":"Y");
}
void DFS(int k,int x,int y)
{
	if(bj||x>n||!Check(total-k+1,x,y))return;
	if(k==total+1&&x!=n)return;
	if(k==total+1&&x==n){Output();return;}
	used[k]=1;DFS(k+1,x+y,y);
	used[k]=0;DFS(k+1,x,x+y);	
}
int main()
{
	n=getint();
	fi[1]=2,fi[2]=3;
	for(ri i=3;i<=30;i++)fi[i]=fi[i-1]+fi[i-2];//获取i次合并最大值 
	for(ri i=1;i<=30;i++)
		if(n<=fi[i]){total=i;break;}//获取最少合并次数
	while(true)
	{
		DFS(1,1,1);
		if(bj)break;
		total++;//未被标记,说明当前的total无法构出可行解,所以要放大total 
	} 	
	return 0;
}

