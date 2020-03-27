#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct Water
{
	string name,score;
	int len;
}King [1005];
int n;
bool cmp(const Water &x,const Water &y)
{
	if(x.len!=y.len)return x.len>y.len;
	else 
		for(int i=0;i<x.len;i++)if(x.score[i]!=y.score[i])
		return x.score[i]>y.score[i];
	return x.name<y.name;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>King[i].name>>King[i].score;
	King[i].len=King[i].score.length();
	}
	sort(King+1,King+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<King[i].name<<endl;
	return 0;
}
