#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int num[21]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<m;i++)next_permutation(num+1,num+n+1);
    for(int i=1;i<=n;i++)cout<<num[i]<<' ';
	return 0;
}
