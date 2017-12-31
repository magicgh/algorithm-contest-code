#include<iostream>
using namespace std;
long a[1005][1005]={0},dx[5]={0,2,1,-1,-1},dy[5]={0,1,2,2,1},n,m;
struct node{int x,y,z;}q[1005];
void walk()
{
   int h,t,x,y,i;
   q[0].x=q[0].y=q[0].z=0;
   h=t=a[0][0]=1;
	while(h<=t) 
   {  for(i=0;i<=3;i++) 
      {  x=q[h].x+dx[i]; y=q[h].y+dy[i];
 if(x>0&&y>0&&x<=n&&y<=m&&!a[x][y]) 
{ t++;q[t].x=x;q[t].y=y; q[t].z=q[h].z+1;a[x][y]=1;}
 if((q[t].x==n)&&(q[t].y==m)) {cout<<q[t].z<<endl;return;}
     }
 h++;
}
}
int main()
{
	cin>>n>>m;
	walk();
	return 0;
}
