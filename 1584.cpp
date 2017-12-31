#include<iostream>
using namespace std;
int used[100]={0},n,a[100]={0};
void PL(int k)
{
     int i;
   if(k>n)
   {for(i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;return;}
      for(i=1;i<=n;i++)
      {
      if(used[i]==0)
      {
      a[k]=i;
      used[i]=1;
      PL(k+1);
      used[i]=0;
      }
      }
      }
int main()
{
    cin>>n;
    PL(1);
//system("pause");
return 0;
}
