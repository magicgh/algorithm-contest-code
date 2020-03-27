#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
int n,L=0,M=1,R=2,RM=3;
char ch[4000005];
deque<char>str[4];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Out_T(){printf("T\n");}
inline void Out_F(){printf("F\n");}
inline char Getchar()
{
	char ch=getchar();
	while(!(ch>=33&&ch<=126))ch=getchar();
	return ch;
}
inline void Output()
{
	string ret;
	for(deque<char>::iterator it=str[L].begin();it!=str[L].end();++it)printf("%c",*it);
	for(deque<char>::iterator it=str[M].begin();it!=str[M].end();++it)printf("%c",*it);
	for(deque<char>::iterator it=str[R].begin();it!=str[R].end();++it)printf("%c",*it);
	printf("\n");
}
void Solve()
{
	int Len=strlen(ch);
	for(ri i=0;i<Len;i++)
		str[M].push_back(ch[i]),str[RM].push_front(ch[i]);
	for(ri i=1;i<=n;i++)
	{
		char op,w,c;
		op=Getchar();
		switch(op)
		{
			case '<':
				w=Getchar();
				if(w=='L')
				{
					if(str[L].size())
					{
						char ch=str[L].back();
						str[L].pop_back();
						str[M].push_front(ch);
						str[RM].push_back(ch);
						Out_T();
					}
					else Out_F();
				}
				if(w=='R')
				{
					if(str[M].size())
					{
						char ch=str[M].back();
						str[M].pop_back();
						str[RM].pop_front();
						str[R].push_front(ch);
						Out_T();
					}
					else if(!str[L].size()&&!str[M].size())Out_F();
				}
			break;
			case '>':
				w=Getchar();
				if(w=='L')
				{
					if(str[M].size())
					{
						char ch=str[M].front();
						str[M].pop_front();
						str[RM].pop_back();
						str[L].push_back(ch);
						Out_T();
					}
					else if(!str[M].size()&&!str[R].size())Out_F();
				}
				if(w=='R')
				{
					if(str[R].size())
					{
						char ch=str[R].front();
						str[R].pop_front();
						str[M].push_back(ch);
						str[RM].push_front(ch);
						Out_T();
					}
					else Out_F();
				}
			break;
			case 'I':
				w=Getchar(),c=Getchar();
				if(w=='L')str[L].push_back(c);
				if(w=='R')str[M].push_back(c),str[RM].push_front(c);
				Out_T();
			break;
			case 'D':
				w=Getchar();
				if(w=='L')
				{
					if(!str[M].size())Out_F();
					else str[M].pop_front(),str[RM].pop_back(),Out_T();
				}
				if(w=='R')
				{
					if(!str[R].size())Out_F();
					else str[R].pop_front(),Out_T();
				}
			break;
			case 'R':
				if(!str[M].size())Out_F();
				else swap(M,RM),Out_T();
			break;
			case 'S':Output();
			break;
		}
	}
}
int main()
{
	scanf("%s",ch);
	n=GetInt();
	Solve();
	return 0;
}

