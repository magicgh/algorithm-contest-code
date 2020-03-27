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
int main()
{
	//freopen("text.in","r",stdin);
	//freopen("text.out","w",stdout);
	int n,a,b,i,j,t1,t2;
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)cout<<'('<<a<<','<<i<<')';
	cout<<endl;
	for(i=1;i<=n;i++)cout<<'('<<i<<','<<b<<')';
	t1=a,t2=b;
	while(t1-1>0&&t2-1>0)t1--,t2--;
	i=t1,j=t2;
	cout<<endl;
	while(i<=n&&j<=n)
	{
		cout<<'('<<i<<','<<j<<')';
		i++,j++;
	}
	t1=a,t2=b;
	while(t1<n&&t2-1>0)t1++,t2--;
	i=t1,j=t2;
	
	
	
	cout<<endl;
	while(i>0&&j<=n)
	{
		cout<<'('<<i<<','<<j<<')';
		i--,j++;
	}
	return 0;
}
