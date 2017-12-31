#include<iostream>
using namespace std;
int main(){
    int n,i,j,maxx=0,maxn=0,maxy=0;
    cin>>n;
    int c[n+5],m[n+5],e[n+5],s[n+5];
    for(i=1;i<=n;i++)
    {
    s[i]=0;
    cin>>c[i]>>m[i]>>e[i];
    s[i]=c[i]+m[i]+e[i];
}
    for(i=1;i<=5;i++)
    {
    for(j=1;j<=n;j++)
    {
     if(s[j]>maxx)
     {
     maxx=s[j];
     maxn=j;
     maxy=c[j];
     }
     if(s[j]==maxx&&c[j]>maxy)
     {
     maxx=s[j];
     maxn=j;
     maxy=c[j];
     }
     }
     cout<<maxn<<" "<<maxx<<endl;
     s[maxn]=maxx=maxy=0;
     }
//system("pause");
return 0;
}
