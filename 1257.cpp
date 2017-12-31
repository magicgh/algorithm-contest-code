#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,k;
 int fen(int a,int b,int c)
 {
     int s=0,i;
     if(b==1)s=1;
     else for(i=c;i<=a/b;i++)s+=fen(a-i,b-1,i);
     return s;
     }
int main(){
     cin>>n>>k;
     cout<<fen(n,k,1);
//system("pause");
return 0;
}
