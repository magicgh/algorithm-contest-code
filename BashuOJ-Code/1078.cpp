#include<iostream>
using namespace std;
int f[1001],a[1001],n,Max=0;

int main(){
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++){cin>>a[i];f[i]=1;}
    for(i=2;i<=n;i++)
    for(j=1;j<i;j++)
      if(a[i]>=a[j]&&f[j]+1>f[i]){f[i]=f[j]+1;}
      for(i=1;i<=n;i++){if(f[i]>f[Max])Max=i;}
        cout<<f[Max]<<endl;
    //system("pause");
    return 0;
}