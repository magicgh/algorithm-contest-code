#include<iostream>
using namespace std;
long long n,m,p,father[5005]={0};
int findfather(int x)
{
	if(father[x]==x)return x;
	father[x]=findfather(father[x]);
	return father[x];
}
void combine(int x,int y)
{
	int a,b;
	a=findfather(x);
	b=findfather(y);
	if(a!=b)father[a]=b;
}
void judge(int x,int y)
{
int a,b;
	a=findfather(x);
	b=findfather(y);
	if(a==b)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

int main(){
cin>>n>>m>>p;
int x,y,z;
for(int i=1;i<=n;i++)
{

father[i]=i;
findfather(i);
}
for(int i=1;i<=m;i++)
{

cin>>x>>y;
combine(x,y);

}
for(int i=1;i<=p;i++)
{

cin>>x>>y;
judge(x,y);
}

	return 0;
}
