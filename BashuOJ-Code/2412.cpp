#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
struct node
{
	int x,y,z;
}map[10005],a;
int N,W,map_len=0;
int prt[10005]={0};
inline void MakeUp()
{
	int i=1;
	for(i=map_len;i>=1;i--)if(map[i].z<=a.z)break;
	for(int j=map_len;j>i;j--)map[j+1]=map[j];
	map[i+1]=a;
	map_len++;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	prt[u]=getfa(prt[u]);
	return prt[u];
}
inline int Kruscal()
{
	int ANS=0,cnt=0;
	for(int i=1;i<=N;i++)prt[i]=i;
	for(int i=1;i<=map_len;i++)
	{
		int f1=getfa(map[i].x);
		int f2=getfa(map[i].y);
		if(f1!=f2)
		{
			prt[f1]=f2;
			cnt++;
			ANS+=map[i].z;
			if(cnt==N-1)break;
		}
	}
	if(cnt<N-1)return -1;
	return ANS;
}
int main(){
	cin>>N>>W;
	for(int i=1;i<=W;i++)
	{
		cin>>a.x>>a.y>>a.z;
		MakeUp();
		int Get=Kruscal();
		printf("%d\n",Get==-1?-1:Get);
	}
	return 0;
}
