#include<iostream>
using namespace std;
long long n,m,p,Friend[30005]={0},c[30005]={0},ans=-0x7fffffff;
int find(int x)
{
	if(Friend[x]==x)return x;
	Friend[x]=find(Friend[x]);
	return Friend[x];
}
void Union(int x,int y)
{
	int t,one,two;
	one=find(x);
	two=find(y);
	if(one!=two)
	{
	Friend[one]=two;
	c[two]+=c[one];
	}
}

int main(){
cin>>n>>m;
int x,y;
for(int i=1;i<=n;i++)
{

Friend[i]=i;
c[i]=1;
}
for(int i=1;i<=m;i++)
{
cin>>x>>y;
Union(x,y);
}
for(int i=1;i<=n;i++)
if(c[i]>=ans)
ans=c[i];
cout<<ans<<endl;
	return 0;
}
