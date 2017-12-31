#include<iostream>
using namespace std;
int n,a[25]={0},t[25]={0},m;
void bag(int v,int k)
{
     if(v<0){return;}
     if(v<m)m=v;
     if(k>n)return;
     bag(v-a[k],k+1);
     bag(v,k+1);
     }
int main()
{
     int v,i;  
         cin>>v>>n;
            for(i=1;i<=n;i++){cin>>a[i];}
            m=v;
        bag(v,1);
         cout<<m;
    //system("pause");
    return 0;
}
