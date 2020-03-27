#include<iostream>
using namespace std;
int n,m,p,father[50005]={0},ans=0;
inline int FindFather(int x)
{
	if(father[x]==x)return x;
	father[x]=FindFather(father[x]);
	return father[x];
}
inline void Combine(int x,int y)
{
	int a,b;
	a=FindFather(x);
	b=FindFather(y);
	if(a!=b)father[a]=b,ans--;
}
int main()
{
	int p=0;
	while(cin>>n>>m,n!=0&&m!=0)
	{
		int x,y;ans=n;++p;
		for(int i=1;i<=n;i++)father[i]=i;
		for(int i=1;i<=m;i++)
		{
		cin>>x>>y;
		Combine(x,y);
		}
		cout<<"Case "<<p<<": "<<ans<<endl;
	}
	return 0;
}