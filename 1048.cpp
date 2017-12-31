#include<iostream>
using namespace std;
int main()
{
    long long l,m,a[10001],i,s=0;
    cin>>l>>m;
    long long kaishi,jiesu;
    for(i=1;i<=10001;i++)
    {
      a[i]=0;
      }
      for(i=1;i<=m;i++)
      {
        cin>>kaishi>>jiesu;
        for(int j=kaishi;j<=jiesu;j++)
        {
          if(a[j]==0)
          {
            a[j]=1;
            s++;
            }
            
          }
          }
          cout<<l-s+1;    cout<<endl;
          
//system("pause");
return 0;
}
