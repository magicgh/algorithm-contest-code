#include<iostream>
using namespace std;
long long a[21][21]={0},f[21][21]={0},n,m,x,y;
int main(){
    int ax[8]={-2,-1,1,2,2,1,-1,-2},ay[8]={1,2,2,1,-1,-2,-2,-1};
    int i,j,cx,cy;
    cin>>n>>m>>x>>y;
    f[x][y]=1;
    a[0][0]=1;
    for(i=0;i<8;i++)
    {
      cx=x+ax[i];
      cy=y+ay[i];
      if(cx>=0&&cx<=n&&cy>=0&&cy<=m)f[cx][cy]=1;
      }
      for(i=1;i<=m;i++){if(f[0][i]==0){a[0][i]=a[0][i-1];}}
      for(i=1;i<=n;i++){if(f[i][0]==0){a[i][0]=a[i-1][0];}}
      for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(f[i][j]==0)
        {a[i][j]=a[i-1][j]+a[i][j-1];}
      cout<<a[n][m];
    //system("pause");
    return 0;
}
