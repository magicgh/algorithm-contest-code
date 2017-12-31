#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cin>>n;
    cout<<n<<endl;
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
          {
             if(i%2==0&&i<j||i%2!=0&&j<=i)cout<<0;
             else if(i%2==0&&j<=i||i%2!=0&&i<j)cout<<1;
             }
             cout<<endl;
             }
//system("pause");
return 0;
}
