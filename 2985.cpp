#include<iostream>
using namespace std;
long long a[1005][1005]={0},n,i,j;
int main(){
    cin>>n;
    for(i=1;i<=n;i++){a[1][i]=1;a[i][1]=1;}
    for(i=2;i<=n;i++)
    {
    for(j=2;j<=n;j++)
    {
    a[i][j]=(a[i-1][j]+a[i][j-1])%100003;
}
}
    cout<<a[n][n];
    //system("pause");
    return 0;
}
