#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
int n,m,tnum;
string t;
map<string,int>ClassSort;
map<string,int>::iterator iter;
struct Koreans
{
	int key;
	string name;
} data[10005];
bool cmp(Koreans a,Koreans b)
{
	if(a.key==b.key)return a.name<b.name;
	else return a.key>b.key;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ClassSort[t]=0;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{

		cin>>tnum>>t;
		ClassSort[t]+=tnum;
	}
	int i=0;
	for(iter=ClassSort.begin();iter!=ClassSort.end();iter++)
	{
		data[++i].name=iter->first;
		data[i].key=iter->second;
	}
	sort(data+1,data+i+1,cmp);
	for(int j=1;j<=i;j++)cout<<data[j].name<<' '<<data[j].key<<endl;
	return 0;
}