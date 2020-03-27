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
struct missile
{
	int l,r;
}
M[100005];
bool cmp(missile a,missile b)
{
	return a.l>b.l;
}
int main(){
	int x1,x2,y1,y2,n,t1,t2,Max=-0x7fffffff,Min=0x7fffffff;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t1>>t2;
		M[i].l=(t1-x1)*(t1-x1)+(t2-y1)*(t2-y1);
		M[i].r=(t1-x2)*(t1-x2)+(t2-y2)*(t2-y2);
	}
	sort(M+1,M+n+1,cmp);
	for(int i=1;i<=n;i++)Max=max(Max,M[i-1].r),Min=min(Min,Max+M[i].l);	
	cout<<Min;
	return 0;
}
