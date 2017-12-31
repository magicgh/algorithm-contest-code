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
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int xi,yi,pi,oi,m,n,l,k,d,i;
	int a[1005]={0},b[1005]={0};
	int t1[1005]={0},t2[1005]={0};
	cin>>m>>n>>k>>l>>d;
	for(i=1;i<=d;i++)
	{
		cin>>xi>>yi>>pi>>oi;
		if(xi!=pi)a[min(xi,pi)]++;
		if(yi!=oi)b[min(yi,oi)]++;
	}
	for(i=1;i<=m;i++)t1[i]=a[i];
	for(i=1;i<=n;i++)t2[i]=b[i];
	sort(a+1,a+m+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(i=1;i<=m;i++)if(t1[i]>=a[k])cout<<i<<' ';
	cout<<endl;
	for(i=1;i<=n;i++)if(t2[i]>=b[l])cout<<i<<' ';
	return 0;
}