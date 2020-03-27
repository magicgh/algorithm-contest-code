#include<iostream>
#include<iomanip>
using namespace std;
 
int main()
{
    int n,i;
    float s,fen;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        s=0;
        cin>>fen;
        s=s+fen;
        cin>>fen;
        s=s+fen;
        cin>>fen;
        s=s+fen;
        cout<<fixed<<setprecision(2)<<s/3<<" ";
    }
   
}
