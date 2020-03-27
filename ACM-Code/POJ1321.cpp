#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
int n,k,cnt,ans;
char Map[10][10];
bool vst[10];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int step)
{
	if(cnt==k){ans++;return;}
	if(step>n)return;
	for(ri i=1;i<=n;i++)
	{
		if(vst[i]||Map[step][i]=='.')continue;
		vst[i]=1,cnt++;
		DFS(step+1);
		vst[i]=0,cnt--;
	}
	DFS(step+1);
}
int main()
{
	while(cin>>n>>k)
	{
		cnt=ans=0;
		memset(vst,0,sizeof(vst));
		if(n==-1&&k==-1)break;
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
				cin>>Map[i][j];
		DFS(1);
		cout<<ans<<endl;
	 } 
    return 0;
}
