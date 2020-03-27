#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int mm=m,nn=n,s=m*n;
    while(mm!=0&&nn!=0)
    {
      mm--;nn--;
      s=s+mm*nn;
      }
      int ss;
      ss=((m+1)*(n+1)*m*n)/4-s;
      cout<<s<<" "<<ss;
      cout<<endl;
//system("pause");
return 0;
}
