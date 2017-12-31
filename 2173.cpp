#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int len=0,cnt=0,n,m;
struct Trie
{
	int ch[26],bj,pos;
	void init(){memset(ch,0,sizeof(ch));bj=0;}
};
Trie tree[1000005];
inline void insert(string s,int t)
{
	int root=0,ch=0;
	for(int i=0;i<s.length();i++)
	{
		ch=s[i]-'a';
		if(tree[root].ch[ch]==0)
		{
			tree[root].ch[ch]=++cnt;
			tree[cnt].init();
			root=cnt;
		}
		else root=tree[root].ch[ch];
	}
	tree[root].bj=1;
	tree[root].pos=t;
}
inline int find(string s)
{
	int root=0,ch=0;
	for(int i=0;i<s.length();i++)
	{
		ch=s[i]-'a';
		root=tree[root].ch[ch];
	}
	cout<<tree[root].pos<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	string s;int x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>x;
		insert(s,x);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		find(s);
	}
	return 0;
}