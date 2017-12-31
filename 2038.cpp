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
#include <map>
using namespace std;
int main()
{
	int n,f[1005]={1,1},i,j;
	cin>>n;
    for(i=2;i<=n;i++)
    {
    	for(j=0;j<=i-2;j++)f[i]=(f[i]+f[j]*f[i-j-2])%12345;
    	f[i]=(f[i-1]+f[i])%12345;
    }
    	cout<<f[n]%12345;
	return 0;
}