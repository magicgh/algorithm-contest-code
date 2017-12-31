#include<iostream>
using namespace std;
string a[105];
int b[105][105],m,n,num=0,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void bfs(int x,int y)
{
int h=0,t=1,i,j,c[10005][2];
c[1][0]=x;c[1][1]=y;
do
{
	h++;
	for(i=0;i<4;i++)
	{
		x=c[h][0]+dx[i];
		y=c[h][1]+dy[i];
		if(x>=0&&x<n&&y>=0&&y<m&&b[x][y])
		{
			t++;
			c[t][0]=x;
			c[t][1]=y;
			b[x][y]=0;
		}
	}
}
while(h<t);
return;
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++)
	   for(j=0;j<m;j++)
	     b[i][j]=a[i][j]-'0';
	     for(i=0;i<n;i++)
	        for(j=0;j<m;j++)
	        if(b[i][j])
	        {
	        	b[i][j]=0;
	        	 bfs(i,j);
	        	 num++;
	        }
	        cout<<num;
	return 0;
}
