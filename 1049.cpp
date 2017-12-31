#include<iostream>
using namespace std;
int s[1005];
int main()
{
    int time,pi,i,j,v,n;
    cin>>time>>pi;
    for(i=1;i<=pi;i++)
    {
       cin>>n>>v;
       for (j=time;j>=n;j--)
           if (s[j-n]+v>s[j])
               s[j]=s[j-n]+v;
    }
    cout<<s[time]<<endl;
    //system("pause");
    return 0;
}
