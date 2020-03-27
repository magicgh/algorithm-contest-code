#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int len=0,cnt=0,n,m;
bool ans=0;
struct Trie
{
	int ch[10],bj,num;
	void init(){memset(ch,0,sizeof(ch));bj=0;num=0;}
};
Trie tree[100005];
inline void insert(string s)
{
	int root=0,ch=0;
	for(int i=0;i<s.length();i++)
	{
		ch=s[i]-'0';
		if(tree[root].bj==1)ans=true;
		if(tree[root].ch[ch]==0)
		{
			tree[root].ch[ch]=++cnt;
			tree[root].num++;
			tree[cnt].init();
			root=cnt;
		}
		else root=tree[root].ch[ch];
	}
	tree[root].bj=1;
	if(tree[root].num>=1)ans=true;
}
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		ans=false;
		cnt=0;
		tree[0].init();
		for(int j=1;j<=m;j++)
		{
			cin>>s;
			insert(s);
		}
		if(ans)puts("NO");
		else puts("YES");
	}
	return 0;
}