#include<iostream>
using namespace std;
int cnt=0,endx=0,endy=0,a[20][20]={0};
void maze(int x,int y)
{
   if(x==endx&&y==endy){cnt++;return;}
   if(a[x][y]==0)return;
   a[x][y]=0;
   maze(x+1,y);
   maze(x-1,y);
   maze(x,y+1);
   maze(x,y-1);
   a[x][y]=1;
}
   int main(){
    int m,n,bx,by;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    {
      cin>>a[i][j];
      }
      cin>>bx>>by>>endx>>endy;
      maze(bx,by);
      if(cnt==0)cout<<-1;
      else cout<<cnt;
   // system("pause");
    return 0;
}
