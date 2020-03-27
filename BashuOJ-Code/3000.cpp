#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}line[1000005];
int n,k=0;
bool cmp(const node &a,const node &b)
{
	return a.y<b.y;
}
int main(){
	//freopen("segment.in","r",stdin);
	//freopen("segment.out","w",stdout);
    scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&line[i].x,&line[i].y);
	sort(line+1,line+n+1,cmp);
	int t=0;
	for(int i=1;i<=n;i++)
	{
		if(t<=line[i].x)k++,t=line[i].y;
	}
	cout<<k;
	return 0;
}
