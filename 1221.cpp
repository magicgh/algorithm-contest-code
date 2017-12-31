#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define M 30005
using namespace std;
struct node
{
	int Prt,Front,Count;
}SET[M];
inline int GetInt()
{
	int num=0;
	char t;
	while(t=getchar(),t>='0'&&t<='9')
	{
		num=num*10+(t-'0');
	}
	return num;
}
inline void Input(char &t,int &x,int &y)
{
	t=getchar(),getchar();
	x=GetInt();
	y=GetInt();
	return;
}
inline int GetFather(int u)
{
	int temp;
	if(SET[u].Prt==u)return u;
	temp=GetFather(SET[u].Prt);
	SET[u].Front+=SET[SET[u].Prt].Front;
	SET[u].Prt=temp;
	return SET[u].Prt;
}
inline void Union(int x,int y)
{
	int root_x=GetFather(x);
	int root_y=GetFather(y);
	if(root_x!=root_y)
	{
	SET[root_x].Prt=root_y;
	SET[root_x].Front=SET[root_y].Count;
	SET[root_y].Count+=SET[root_x].Count;
	}
	return;
}
inline void Output(int x,int y)
{
	if(GetFather(x)==GetFather(y))printf("%d\n",abs(SET[x].Front-SET[y].Front)-1);
	else putchar('-'),putchar('1'),putchar('\n');
	return;
}
int main(){
	char t;
	int x,y,n;
	n=GetInt();
	for(int i=1;i<=M;i++)SET[i].Prt=i,SET[i].Count=1,SET[i].Front=0;
	for(int i=1;i<=n;i++)
	{
		Input(t,x,y);
		t=='M'?Union(x,y):Output(x,y);
	}
	return 0;
}
