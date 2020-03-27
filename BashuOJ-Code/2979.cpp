#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int len=0,cnt=0,n,m,ans=0;
struct Trie
{
	int ch[80],bj;
	Trie(){memset(ch,0,sizeof(ch));bj=0;}
};
Trie tree[100005];
inline void insert(string s)
{
	int root=0,ch=0;
	for(int i=1;i<s.length();i++)
	{
		ch=s[i]-'/';
		if(tree[root].ch[ch]==0)
		{
			tree[root].ch[ch]=++cnt;
			if(ch==0)ans++;
			root=cnt;
		}
		else root=tree[root].ch[ch];
	}
	tree[root].bj=1;
}
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		s=s+"/";
		insert(s);
		printf("%d\n",ans);
	}
	return 0;
}