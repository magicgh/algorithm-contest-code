#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
struct heap{
	bool map[5][5];
	int step;
};
bool S[5][5],T[5][5],H[65540];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int tid; 
inline int Hash(bool t[5][5])
{
	int id=0,Base=1;
	for(ri i=1;i<=4;i++)
		for(ri j=1;j<=4;j++)
			id+=t[i][j]*Base,Base<<=1;
	return id;
}
void BFS()
{
	queue<heap>q;
	heap tmp;
	for(ri i=1;i<=4;i++)
		for(ri j=1;j<=4;j++)tmp.map[i][j]=S[i][j];
	tmp.step=0;
	q.push(tmp);
	while(!q.empty())
	{
		heap now=q.front();q.pop();
		if(Hash(now.map)==tid)
		{
			printf("%d\n",now.step);
			break;
		}
		for(ri i=1;i<=4;i++)
			for(ri j=1;j<=4;j++)
			{
				if(!now.map[i][j])continue;
				for(ri k=0;k<4;k++)
				{
					int nx=i+dx[k],ny=j+dy[k];
					if(nx>=1&&nx<=4&&ny>=1&&ny<=4&&!now.map[nx][ny])
					{
						heap next=now;
						next.map[i][j]=0;
						next.map[nx][ny]=1;
						next.step++;
						if(!H[Hash(next.map)])
							q.push(next),H[Hash(next.map)]=1;
					}
				}
			}
	}
}
int main()
{
	char ch;
	for(ri i=1;i<=4;i++)
		for(ri j=1;j<=4;j++)
		{
			while(ch=getchar())
				if(ch=='0'||ch=='1')break;
			S[i][j]=ch-'0';
		}
	H[Hash(S)]=1;
	for(ri i=1;i<=4;i++)
		for(ri j=1;j<=4;j++)
		{
			while(ch=getchar())
				if(ch=='0'||ch=='1')break;
			T[i][j]=ch-'0';
		}
	tid=Hash(T);
	BFS();
	return 0;
}
