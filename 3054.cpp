#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
string str,T;
int n,cnt;
struct Trie
{
	int ch[55];bool bj;
	Trie(){memset(ch,0,sizeof(ch));bj=0;}
};
Trie Tree[4005];
bool Title;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Todigit(char &ch)
{
	if(isalpha(ch))return (ch-'a'+3);
	if(ch=='.')return 1;
	if(ch=='/')return 2;
}
inline char Tochar(int &x)
{
	if(x==1)return '.';
	if(x==2)return '/';
	if(x>=3&&x<=28)return char(94+x);
}
inline void Insert(string str)
{
	int root=0,pos=0;
	for(ri i=0;i<str.length();i++)
	{
		pos=Todigit(str[i]);
		if(Tree[root].ch[pos]==0)
		{
			Tree[root].ch[pos]=++cnt;
			root=cnt;
		}
		else root=Tree[root].ch[pos];
	}
	Tree[root].bj=1;
}
inline void OutTitle(string T)
{
	Title=1;
	for(ri i=0;i<T.length();i++)cout<<T[i];
	cout<<endl;
}
inline void OutFile(int k,string T)
{
	for(ri i=1;i<k;i++)cout<<"|    ";
	cout<<"|----";
	for(ri i=0;i<T.length();i++)cout<<T[i];
	cout<<endl;
}
inline void Output(int u,int dep,string T)
{
	for(ri i=1;i<=28;i++)
	{
		if(Tree[u].ch[i])
		{
			if(i==2)
			{
				if(!dep)OutTitle(T);
				else OutFile(dep,T);
			}
			if(i==2)Output(Tree[u].ch[i],dep+1,"");
			else Output(Tree[u].ch[i],dep,T+Tochar(i));
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(ri i=1;i<=n;i++)
	{
		cin>>str;
		str+='/';
		Insert(str);
	}
	Output(0,0,"");
	return 0;
}

