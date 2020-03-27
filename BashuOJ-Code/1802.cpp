#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#define ri register int
using namespace std;
vector<string>word,ans;
map<string,int>cnt;
string s;
inline string reorder(const string &a)
{
	string t=a;
	for(ri i=0;i<t.length();i++)t[i]=toupper(t[i]);
	sort(t.begin(),t.end());
	return t;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>s,s!="#")
	{
		word.push_back(s);
		string t=reorder(s);
		if(!cnt.count(t))cnt[t]=0;
		cnt[t]++;
	}
	for(auto it=word.begin();it!=word.end();++it)
	 	if(cnt[reorder(*it)]==1)ans.push_back(*it);
	sort(ans.begin(),ans.end());
	for(auto it=ans.begin();it!=ans.end();++it)cout<<*it<<endl;
	return 0;
}
//强制 C++11 测试 