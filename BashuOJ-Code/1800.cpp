#include<iostream>
#include<cstring>
const int Max=0x7fffffff;
using namespace std;
int a[105][105],x1,x2,y1,y2,s[10000][5];
int head,tail,i,x,y;
int dx[12]={-2,-2,-1,1,2,2,2,2,1,-1,-2,-2};
int dy[12]={-1,-2,-2,-2,-2,-1,1,2,2,2,2,1};
void bfs()
{
   s[1][3]=head=0;tail=s[1][1]=s[1][2]=1;
	do
	{
		for(i=0;i<12;i++)
		{
			x=s[head][1]+dx[i];
			y=s[head][2]+dy[i];
			if(x>0&&y>0&&a[x][y]==-1)
			{
				a[x][y]=s[head][3]+1;
				tail++;
				s[tail][1]=x;s[tail][2]=y;
				s[tail][3]=a[x][y];
				if(a[x1][y1]>0&&a[x2][y2]>0)
				{
					cout<<a[x1][y1]<<endl<<a[x2][y2]<<endl;
					return;
				}
			}
		}
		head++;
	}
	while(head<=tail);
	return;
}
int main(){
	memset(a,Max,sizeof(a));
	memset(s,0,sizeof(s));
	cin>>x1>>y1>>x2>>y2;
	   	bfs();
		return 0;
}
