/*
ID: baymax01
PROG: text
LANG: C++                  
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <cassert>
#include <cctype>
#include <queue>
using namespace std;
int main(){
	int n,hi[80005]={0},stack[80005]={0},k=0;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>hi[i];
	for(int i=1;i<=n;i++)
	{
			while(hi[i]>=stack[k]&&k)k--;
			ans+=k;//记录可以看见的牛（栈中） 
		stack[++k]=hi[i];//入栈 
}
	cout<<ans;
	return 0;
}
