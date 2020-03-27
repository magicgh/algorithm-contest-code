#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=0x7fffffff;
int N,M;
int InDgree[105]={0},TopOrder[105]={0},f[105]={0},map[105][105]={0};
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
	for(int i=1;i<=N;i++)
	{
		int j=1;
		while(j<=N&&InDgree[j]>0)j++;
		TopOrder[i]=j;
		InDgree[j]=MAXN;
		for(int k=1;k<=N;k++)if(map[j][k])InDgree[k]--;
	}
	return;
}
void DP()
{
	for(int i=2;i<=N;i++)
	   for(int j=1;j<=i-1;j++)
	      {
	       if(map[TopOrder[j]][TopOrder[i]])
	         {
	         	f[TopOrder[i]]=max(f[TopOrder[i]],f[TopOrder[j]]+map[TopOrder[j]][TopOrder[i]]);
			 }
		}
			 return;
}
int main(){
	Input();
	Topsort();
	DP();
	printf("%d",f[TopOrder[N]]);
	return 0;
}
