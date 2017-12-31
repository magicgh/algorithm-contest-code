#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=0x7fffffff;
int N,M;
int InDgree[105]={0},TopOrder[105]={0},f[105]={0},map[105][105]={0},prt[105]={0};
int Point[105]={0},cnt=0;
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
void Input()
{
	N=GetInt();
	M=GetInt();
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		map[x][y]=z;
		InDgree[y]++;
	}
	return;
}
void Topsort()
{
	for(int i=1;i<=N+1;i++)
	{
		int j=1;
		while(j<=N+1&&InDgree[j]>0)j++;
		TopOrder[i]=j;
		InDgree[j]=MAXN;
		for(int k=1;k<=N+1;k++)if(map[j][k])InDgree[k]--;
	}
	return;
}
void DP()
{
	for(int i=2;i<=N+1;i++)
	   for(int j=1;j<=i-1;j++)
	      {
	       if(map[TopOrder[j]][TopOrder[i]]&&f[TopOrder[i]]<f[TopOrder[j]]+map[TopOrder[j]][TopOrder[i]])
	         {
	         	f[TopOrder[i]]=f[TopOrder[j]]+map[TopOrder[j]][TopOrder[i]];
	         	prt[TopOrder[i]]=TopOrder[j];
			 }
		}
			 return;
}
int main(){
	Input();
	Topsort();
	DP();
	printf("%d\n",f[TopOrder[N+1]]);
	for(int i=N+1;i!=0;i=prt[i])Point[++cnt]=i;
	sort(Point+1,Point+cnt+1);
	for(int i=1;i<=cnt;i++)printf("%d ",Point[i]);
	return 0;
}
