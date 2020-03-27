/*
ID: baymax01
PROG: milk3
LANG: C++                  
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
bool M[25][25][25],Rec[105];
struct Milk
{
	int a;
	int b;
	int c;
}Max;
void dfs(int a,int b,int c)
{
	if(M[a][b][c]==1)return;
	else M[a][b][c]=1;
	if(a==0&&Rec[c]==0)Rec[c]=1;
	
	if(Max.a-a>c)dfs(a+c,b,0);//c->a
	else dfs(Max.a,b,c-(Max.a-a));
	
	if(Max.b-b>c)dfs(a,b+c,0);//c->b
	else dfs(a,Max.b,c-(Max.b-b));
	
	if(Max.a-a>b)dfs(a+b,0,c);//b->a
	else dfs(Max.a,b-(Max.a-a),c);
	
	if(Max.c-c>b)dfs(a,0,c+b);//b->c
	else dfs(a,b-(Max.c-c),Max.c);
	
	if(Max.b-b>a)dfs(0,b+a,c);//a->b
	else dfs(a-(Max.b-b),Max.b,c);
	
	if(Max.c-c>a)dfs(a+c,b,0);//a->c
	else dfs(a-(Max.c-c),b,Max.c);
	return;
}
int main(){
	int i;
	//freopen("milk3.in","r",stdin);
	//freopen("milk3.out","w",stdout);
	memset(M,0,sizeof(M));
	memset(Rec,0,sizeof(Rec));
     cin>>Max.a>>Max.b>>Max.c;
     dfs(0,0,Max.c);
     for(i=0;i<=Max.c;i++)
     {
     if(Rec[i])
	 {
	 cout<<i;
     if(i<Max.c)cout<<' ';
	 }
     }
	 cout<<endl;
	return 0;
}