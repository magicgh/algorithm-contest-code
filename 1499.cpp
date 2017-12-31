#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
struct node
{
	int x,y,z;
}w[50005];
int e[11];
int n,k;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(node aa,node bb)
{
	return (aa.y>bb.y)||(aa.y==bb.y&&aa.x<bb.x);
}
using namespace std;
int main(){
	cin>>n>>k;
	for(int i=1;i<=10;i++)e[i]=GetInt();
	for(int i=1;i<=n;i++)
		w[i]=(node){i,GetInt(),0};
	sort(w+1,w+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		w[i].z=(i-1)%10+1;
		w[i].y+=e[w[i].z];
	}
	sort(w+1,w+n+1,cmp);
	for(int i=1;i<=k;i++)printf("%d ",w[i].x);
	return 0;
}
