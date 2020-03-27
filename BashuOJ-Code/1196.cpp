#include<iostream>
using namespace std;
long long a[105][3],b[1005]={0};
int dfs(int l,int r)
{if(a[l][1]!=0)dfs(a[l][1],r);
  if(r==2)cout<<l<<endl;
  if(a[l][2]!=0)dfs(a[l][2],r);
  return 0;      
}     
int main()
{
    int i,root,n,t;
    cin>>n;
    for(i=1;i<=n;i++)
    {
         cin>>t;
         cin>>a[t][1]>>a[t][2];
         b[a[t][1]]=b[a[t][2]]=1;
         }
         for(i=1;i<=n;i++)
         {
           if(b[i]==0){root=i;break;}
           }       
           dfs(root,2);cout<<endl;
     
           return 0;
           }   