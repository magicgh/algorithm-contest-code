#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int N,a[15],t[15],Hash[15][390000];
bool vst[15][390000];
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
inline int DFS(int t1,int t2)
{
	if(t1==N+1)return 1;
	if(t2==N+1)
	{
		int num=0;
		if(a[t1]!=0)return 0;
		for(int i=1;i<=N-t1;i++)t[i]=a[i+t1];
		sort(t+1,t+1+N-t1);
		for(int i=1;i<=N-t1;i++)num=(num*41+t[i])%389911;
		if(!vst[N-t1][num])
		{
			Hash[N-t1][num]=DFS(t1+1,t1+2);
			vst[N-t1][num]=1;
		}
		return Hash[N-t1][num];
	}
	if(a[t1]>(N-t2+1)*3)return 0;
	int ans=0;
	if(a[t1]>=1&&a[t2]>=1)
	{
		a[t1]--;a[t2]--;
		ans+=DFS(t1,t2+1);
		a[t1]++;a[t2]++;
	}
	if(a[t1]>=3)
	{
		a[t1]-=3;
		ans+=DFS(t1,t2+1);
		a[t1]+=3;
	}
	if(a[t2]>=3)
	{
		a[t2]-=3;
		ans+=DFS(t1,t2+1);
		a[t2]+=3;
	}
	return ans;
}
int main(){
	N=GetInt();
	for(int i=1;i<=N;i++)a[i]=GetInt();
	printf("%d",DFS(1,2));
	return 0;
}
