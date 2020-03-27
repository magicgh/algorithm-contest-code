#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
string s1,s2;
int DFS(int l1,int r1,int l2,int r2)
{
	int i,j;
	if((l1==r1)||(l2==r2))return 1;
	j=l1+1;
	for(i=r2-1;i>=l2;i--)
		if(s1[j]==s2[i])break;
	if(i+1==r2)return DFS(l1+1,r1,l2,i)*2;
	else return DFS(l1+1,l1+1+i-l2,l2,i)*DFS(l1+1+i-l2+1,r1,i+1,r2-1);
}
int main()
{
	cin>>s1>>s2;
	int len=s1.length()-1;
	cout<<DFS(0,len,0,len);
	return 0;
}

