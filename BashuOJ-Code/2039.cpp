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
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	int n,f[1005][5]= {0},i;
	cin>>n;
	n+=1;
	f[1][0]=1;
	f[1][1]=0;
	for(i=2; i<=n; i++) {
		f[i][0]=(3*f[i-1][0]+f[i-1][1]*2)%12345;
		f[i][1]=(f[i-1][0]+f[i-1][1])%12345;
	}
	cout<<(f[n][0]+f[n][1])%12345;
	return 0;
}