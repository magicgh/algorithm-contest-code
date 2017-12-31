#include<iostream>
using namespace std;
int a[105][105]={0},f[105][105]={0},c[55][55]={0},d[55]={0};
int main(){
    int n,i,j,k,maxx=0,maxk=0,l=1;
    cin>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=i;j++)
            cin>>a[i][j];
    for(i=1;i<=n;i++)f[n][i]=a[n][i];
    for(i=n-1;i>=1;i--)
         {
           for(j=1;j<=i;j++)
             {
             f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
             }
             }
             cout<<f[1][1]<<endl;
             
    //system("pause");
    return 0;
}