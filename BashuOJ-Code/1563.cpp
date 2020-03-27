#include<iostream>
using namespace std;
const int R=0;
const int D=1;
const int RU=2;
const int LD=3;
int main(){
    int a[15][15]={1};
    int s=D,dir=0,i=1,x=0,y=0,n;
    cin>>n;
    while(i!=n*n)
    {
      switch(s){
      case D:
      y++;
      a[x][y]=++i;
      s=dir?LD:RU;
      break;
      case R:
      x++;
      a[x][y]=++i;
      s=dir?RU:LD;
      break;
      case RU:
      if(y-1<0&&x+1==n){dir=1;s=D;}
      else if(y-1<0)s=R;
      else if(x+1==n)s=D;
      else a[++x][--y]=++i;
      break;
      case LD:
      if(y+1==n&&x-1<0){dir=1;s=R;}
      else if(y+1==n)s=R;
      else if(x-1<0)s=D;
      else a[--x][++y]=++i;
      break;
      }
      }
      for(int i=0;i<n;i++)
      {
       for(int j=0;j<n;j++)
       cout<<a[j][i]<<" ";
       cout<<endl;
       }
   
    //system("pause");
    return 0;
}
