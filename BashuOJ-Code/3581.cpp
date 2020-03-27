#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int len=0,cnt=0,n,m,ans=0;
struct Trie
{
	int ch[26],bj;
	Trie(){memset(ch,0,sizeof(ch));bj=0;}
};
Trie tree[100005];
inline void insert(string s)
{
	int root=0,ch=0;
	for(int i=0;i<s.length();i++)
	{
		ch=s[i]-'a';
		if(tree[root].ch[ch]==0)
		{
			tree[root].ch[ch]=++cnt;
			root=cnt;
		}
		else root=tree[root].ch[ch];
	}
	tree[root].bj=1;
}
long long DP(int root)
{
	long long ans=1;
	for(int i=0;i<26;i++)
	if(tree[root].ch[i]>0)ans=ans*DP(tree[root].ch[i]);
	return ans+tree[root].bj;
}
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		insert(s);
	}
	printf("%lld",DP(0));
	return 0;
}