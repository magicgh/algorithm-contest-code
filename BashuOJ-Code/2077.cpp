/*
ID: baymax01
PROG: frac1
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
int  n;
void f(int a,int b,int c,int d)
{
	if(b+d>n)return;
	f(a,b,a+c,b+d);
	cout<<a+c<<'/'<<b+d<<endl;
	f(a+c,b+d,c,d);
}
int main()
{
    //freopen("frac1.in","r",stdin);
	//freopen("frac1.out","w",stdout);
	cin>>n;
	cout<<"0/1"<<endl;
	f(0,1,1,1);
	cout<<"1/1"<<endl;
	return 0;
}
