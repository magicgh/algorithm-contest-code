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
#include<set>
#include<map>
#define ri register int
#define ll long long
using namespace std;
int n,m;
map<int,int>Holder;
struct heap
{
	int L,R;
	bool operator <(const heap &rhs)
	const
	{
		int Mid1=(L+R)>>1,Mid2=(rhs.L+rhs.R)>>1;
		int Dis1=(L==0||R==n+1)?R-L-1:min(Mid1-L,R-Mid1);
		int Dis2=(rhs.L==0||rhs.R==n+1)?rhs.R-rhs.L-1:min(Mid2-rhs.L,rhs.R-Mid2);
		return (Dis1==Dis2&&L>rhs.L)||(Dis1<Dis2);
	}
};
set<int>s;
priority_queue<heap>q;
inline int Prev(const int &key_value){return *(--s.lower_bound(key_value));}
inline int Next(const int &key_value){return *s.upper_bound(key_value);}
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check()
{
	int l=q.top().L,r=q.top().R;
	return (Prev(r)!=l||Next(l)!=r);
}
inline int Add(int id,int pos)
{
	Holder[id]=pos;
	s.insert(pos);
	int Lpos=Prev(pos),Rpos=Next(pos); 
	if(pos-Lpos-1>0)q.push((heap){Lpos,pos});
	if(Rpos-pos-1>0)q.push((heap){pos,Rpos});
	return pos;
}
inline void Delete(int pos)
{
	s.erase(pos);
	int Lpos=Prev(pos),Rpos=Next(pos); 
	if(Rpos-Lpos-1>0)q.push((heap){Lpos,Rpos});
}
inline int Insert(int x)
{
	while(!q.empty()&&Check())q.pop();
	int l=q.top().L,r=q.top().R;q.pop();
	if(l==0)return Add(x,1);
	else if(r==n+1)return Add(x,n);
	else return Add(x,(l+r)>>1);
}
int main()
{
	n=GetInt(),m=GetInt();
	s.insert(0),s.insert(n+1);
	q.push((heap){0,n+1});
	for(ri i=1;i<=m;i++)
	{
		int op=GetInt(),x=GetInt();
		switch(op)
		{
			case 1:printf("%d\n",Insert(x));
			break;
			case 2:Delete(Holder[x]);
			break;
		}
	}
	return 0;
}


