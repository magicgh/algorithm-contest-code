#include<iostream>
using namespace std;
int n,a[30]={0},b[30]={0},c[30]={0},s[30]={0},f=0,cnt=0;
void queen(int i)
{
int p,j;
     if(i>n)
     {
      cnt++;
      if(cnt>3)return;
       for(p=1;p<=n;p++)cout<<a[p]<<" ";
       cout<<endl;f=1;
       }
       for(j=1;j<=n;j++)
       {
         if(s[j]==0&&b[i+j]==0&&c[i-j+n]==0)
         {
           a[i]=j;
           s[j]=1;
           b[i+j]=1;
           c[i-j+n]=1;
           queen(i+1);
           s[j]=0;
           b[i+j]=0;
           c[i-j+n]=0;
           }
           }
           return;
           }
int main(){
    cin>>n;
    queen(1);
    cout<<cnt;
    return 0;
}