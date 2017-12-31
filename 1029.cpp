#include <iostream>
#include <queue>
using namespace std;
int n,a,b,floor[205]={0};
bool used[205]={0};
int updown[3]={0,1,-1};
struct node
{
	int to,cnt;
};
inline int BFS(int st,int ed)
{
	queue<node>q;
	used[st]=1;
	q.push({st,0});
	while(!q.empty())
	{
		node now=q.front();
		if(now.to==ed)return now.cnt;
		for(int i=1;i<=2;i++)
		{
			node next={now.to+updown[i]*floor[now.to],now.cnt+1};
			if(next.to>=1&&next.to<=n&&(!used[next.to]))
			{
				used[next.to]=1;
				q.push(next);
			}
		}
		q.pop();
	}
	return -1;
}
int main() {
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)cin>>floor[i];
	cout<<BFS(a,b);
	return 0;
}