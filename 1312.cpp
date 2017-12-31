#include<iostream>
#include<cmath>
using namespace std;
struct point
{ int x,y;}space;
int dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1};
int a[4][4],map[4][4],i,j,dif,ans;
int goal[9][3]={
               0,1,1,
               0,1,2,
               0,1,3,
               0,2,1,
			   0,2,2,
			   0,2,3,
			   0,3,1,
			   0,3,2,
			   0,3,3,
};
bool find1;
bool ok(int x,int y)
{
  if(x>0&&y>0&&x<4&&y<4)return true;
      return false;
}

void IDA(int dif,int x,int p,point space)
{  int m,i,j;point s;
   if(dif>x)return;
   if(x==0&&dif==0)
      {find1=true;return;}
   for(i=1;i<=4;i++)
       if(ok(space.x+dx[i],space.y+dy[i]))
         {
            s.x=space.x+dx[i];
            s.y=space.y+dy[i];
            j=a[s.x][s.y];
            swap(a[s.x][s.y],a[space.x][space.y]);
            m=abs(goal[j][1]-s.x)+abs(goal[j][2]-s.y)-abs(goal[j][1]-space.x)-abs(goal[j][2]-space.y);
            IDA(dif-m,x-1,i,s);
            if(find1)return;
            swap(a[s.x][s.y],a[space.x][space.y]);
         }
}
void ready()
{  int i,j;
   for(i=1;i<=3;i++)
     for(j=1;j<=3;j++)
       if(map[i][j]!=0)
         dif+=abs(goal[map[i][j]][1]-i)+abs(goal[map[i][j]][2]-j);
   else
    {space.x=i;space.y=j;}
}
int main()
{  
     for(i=1;i<=3;i++)
     for(j=1;j<=3;j++)cin>>map[i][j];  
   ready();
   find1=false;
   for(ans=dif;ans<=28;ans++)
     {
       for(i=1;i<=3;i++)
         for(j=1;j<=3;j++)a[i][j]=map[i][j];
       IDA(dif,ans,0,space);
       if(find1){cout<<ans<<endl;break;}
     }
 if(!find1)cout<<-1<<endl;
 return 0;
}