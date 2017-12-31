#include<iostream>
using namespace std;
int a[40]={0},b[40]={0};
void FJ(int n,int s,int h)
{int i,j;
   for(i=s;i<=n/2;i++)
   { a[h]=i;
     b[h]=n-i;
     for(j=1;j<=h;j++)
     cout<<a[j]<<"+";
     cout<<b[h]<<endl;
      FJ(b[h],i,h+1);}}
int main(){
    int n;
    cin>>n;
    FJ(n,1,1);
    //system("pause");
    return 0;}
