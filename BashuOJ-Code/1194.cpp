#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int len=0,cnt=0;
struct Trie
{
	int ch[26];
	bool bj;
	Trie(){memset(ch,0,sizeof(ch));bj=0;}
};
Trie tree[100005];
inline void insert(string s)
{
	int root=0,ch=0;
	for(int i=0;i<s.length();i++)
	{
		ch=s[i]-'A';
		if(tree[root].ch[ch]==0)
		{
			tree[root].ch[ch]=++cnt;
			root=cnt;
		}
		else root=tree[root].ch[ch];
	}
	tree[root].bj=1;
}
inline bool find(string s)
{
	int root=0,ch=0;
	for(int i=0;i<s.length();i++)
	{
		ch=s[i]-'a';
		if(tree[root].ch[ch]==0)return 0;
		else root=tree[root].ch[ch];
	}
	if(tree[root].bj==1)return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s)
	{
		insert(s);
		
	}
	printf("%d\n",cnt+1);	
	return 0;
}
