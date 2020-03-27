#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
int N,M,Rn=0,Ans=0;
struct node
{
	int lx,ly,rx,ry;
};
node Rec[20005],Now;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Cross(int x1,int x2,int x3,int x4)//判断线段是否相交 
{return (x1>=x4||x3>=x2)?0:1;}
inline void Cut(int lx,int ly,int rx,int ry,int cmd)
{
	if(cmd==1)//x方向的切割 
	{
		int k1=max(lx,Now.lx);
		int k2=min(rx,Now.rx);
		if(k1>lx)Rec[++Rn]=(node){lx,ly,k1,ry};
		if(k2<rx)Rec[++Rn]=(node){k2,ly,rx,ry};
		Cut(k1,ly,k2,ry,2);		
	}
	if(cmd==2)//y方向切割
	{
		int k1=max(ly,Now.ly);
		int k2=min(ry,Now.ry);
		if(k1>ly)Rec[++Rn]=(node){lx,ly,rx,k1};
		if(k2<ry)Rec[++Rn]=(node){lx,k2,rx,ry};
		Ans+=(rx-lx)*(k2-k1);
	} 
}
inline void Delete()
{
	Ans=0;
	for(int i=0;i<=Rn;i++)
	{
		if(Cross(Now.lx,Now.rx,Rec[i].lx,Rec[i].rx)&&Cross(Now.ly,Now.ry,Rec[i].ly,Rec[i].ry))
		{
		Cut(Rec[i].lx,Rec[i].ly,Rec[i].rx,Rec[i].ry,1);
		//若两矩形相交 开始切割
		Rec[i]=Rec[Rn];
		Rn--;i--;
		}
	}
	printf("%d\n",Ans);
}
int main(){
	int k,x1,x2,v;
	N=GetInt();
	M=GetInt();
	for(int i=1;i<=M;i++)
	{
		k=GetInt();
		x1=GetInt();
		x2=GetInt();
		v=GetInt();
		Now=(node){x1-1,0,x2,v};	
		if(k==1)Rec[++Rn]=Now;
		if(k==2)Delete();
	}
	return 0;
}