/*
借鉴-手工链式前向星版本
STL版本未完成 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN=1000005;
int Head[MAXN],End[MAXN],color[MAXN],fnum[MAXN],Size[MAXN],Next[MAXN];
//Head[x]连接链表的第一个元素
//End[x]链表的最后一个元素
//Next[x]指向链表的下一个元素
//链式前向星 类于栈的结构 
int Ans=0,N,M;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
void Merge(int x,int y)
{
	for(int i=Head[x];i;i=Next[i])//前后检查维护 
	{
		if(color[i+1]==y)Ans--;
		if(color[i-1]==y)Ans--;
	}
	for(int i=Head[x];i;i=Next[i])color[i]=y;//更改小链表的颜色信息 
	Next[End[x]]=Head[y];
	Head[y]=Head[x];
	Size[y]+=Size[x];//连接两链表 
	End[x]=Head[x]=Size[x]=0;//清空小链表 
}
int main(){
	int x,y,c;
	N=GetInt();M=GetInt();
	for(int i=1;i<=N;i++)
	{
		color[i]=GetInt();
		if(color[i]!=color[i-1])Ans++;//维护答案 
		fnum[color[i]]=color[i];//初始化映射 
		if(!Head[color[i]])End[color[i]]=i;//初始化新颜色的链表 
		Next[i]=Head[color[i]];Head[color[i]]=i;Size[color[i]]++;//维护链表 
	}
	for(int i=1;i<=M;i++)
	{
			c=GetInt();
			if(c==1)
			{
			x=GetInt();y=GetInt();
			if(x==y)continue;//相同无需合并
			if(Size[fnum[x]]>Size[fnum[y]])swap(fnum[x],fnum[y]);//保证x链表的元素个数小于y链表的元素个数 
			int t1=fnum[x],t2=fnum[y];//临时存储
			if(Size[t1]==0)continue;//链表为空无需合并 
			Merge(t1,t2); 
			}
			if(c==2)printf("%d\n",Ans);
	}
	return 0;
}
