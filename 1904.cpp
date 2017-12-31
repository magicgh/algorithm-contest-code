#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<map>
using namespace std;
int n,m,tnum,num[1005];
string t;
int main(){
	map<string,int>ClassSort;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ClassSort[t]=0;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int NUM=1;
		for(int j=1;j<=n;j++)
     {
		cin>>tnum>>t;
		ClassSort[t]+=tnum;
		}   
	map<string,int>::iterator iter;
	for(iter=ClassSort.begin();iter!=ClassSort.end();iter++)if(iter->second>ClassSort["JLY"])NUM++;
	cout<<NUM<<endl;
	}
	return 0;
}