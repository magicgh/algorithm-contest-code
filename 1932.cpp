#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,Min=0x7fffffff,ans[1005],Degree[1005];
bool map[1005][1005];
inline int Caps(char a)
{
	if(a>='A'&&a<='Z')return a-'A'+1;
	if(a>='a'&&a<='z')return a-'a'+27;
}
inline void Output(int key)
{
	if(key>=1&&key<=26)cout<<char(key-1+'A');
	if(key>=27&&key<=52)cout<<char(key-27+'a');
}
inline void DFS(int x,int k)
{
	if(k==n+2)
	{
		for(int i=1;i<=n+1;i++)Output(ans[i]);
		exit(0);
	}
	for(int i=1;i<=52;i++)
	{
		if(map[x][i])
		{
			map[x][i]=map[i][x]=0;
			ans[k]=i;
			DFS(i,k+1);
			map[x][i]=map[i][x]=1;
		}
	}
}
int main(){
	cin>>n;
	char a,b;
	memset(map,0,sizeof(map));
	memset(Degree,0,sizeof(Degree));
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		int t1=Caps(a),t2=Caps(b);
		map[t1][t2]=map[t2][t1]=1;
		Degree[t1]++,Degree[t2]++;
		Min=min(t1,min(t2,Min));
	}
	int cnt=0;
	for(int i=52;i>=1;i--)if(Degree[i]%2==1)cnt++,Min=i;
	if(cnt==0||cnt==2)
	{
	ans[1]=Min;
	DFS(Min,2);
	}
	else 
	{
		puts("No Solution");
	}
	return 0;
}