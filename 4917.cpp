#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
struct node
{
	int n,t;
};
int Hash[300005]={0};
int ans=0;
queue<node>q;
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
int n,k;
int main(){
	n=GetInt();
	for(int i=1;i<=n;i++)
	{
		int t=GetInt(),k=GetInt();
		for(int j=1;j<=k;j++)
		{
		int x=GetInt();
		if(!Hash[x])ans++;
		Hash[x]++;
		q.push((node){x,t});		
	    }	
	   	 while(!q.empty()&&q.front().t<=t-86400)
	    {
	    	Hash[q.front().n]--;
	    	if(!Hash[q.front().n])ans--;
	    	q.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
