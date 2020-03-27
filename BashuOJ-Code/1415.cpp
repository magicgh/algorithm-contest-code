#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int map[8][8]=
{
	{2,3,4,4,4,4,3,2},
	{3,4,6,6,6,6,4,3},
	{4,6,8,8,8,8,6,4},
	{4,6,8,8,8,8,6,4},
	{4,6,8,8,8,8,6,4},
	{4,6,8,8,8,8,6,4},
	{3,4,6,6,6,6,4,3},
	{2,3,4,4,4,4,3,2},

};
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a;
		int str=a.length();
	    cout<<map[int(a[0]-97)][a[1]-'0'-1]<<endl;
	}
	return 0;
}