#include<iostream>
using namespace std;
int main(){
    int n,a,b,i,max,min;
    cin>>n>>b;
    max=b;
    min=b;
    for(i=1;i<n;i++)
{   cin>>b;
    if(b>max) max=b;
    if(b<min) min=b;
}
    cout<<max<<" "<<min;           
    //system("pause");
    return 0;
}
