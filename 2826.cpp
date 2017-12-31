#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
int N,M,Rn=0,Rt=0;
struct node
{
	int lx,rx,ly,ry,lz,rz;
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
inline void Cut(int lx,int rx,int ly,int ry,int lz,int rz,int cmd)
{
	if(cmd==1)//x方向的切割 
	{
		int k1=max(lx,Now.lx);
		int k2=min(rx,Now.rx);
		if(k1>lx)Rec[++Rn]=(node){lx,k1,ly,ry,lz,rz};
		if(k2<rx)Rec[++Rn]=(node){k2,rx,ly,ry,lz,rz};
		Cut(k1,k2,ly,ry,lz,rz,2);			
	}
	if(cmd==2)//y方向切割
	{
		int k1=max(ly,Now.ly);
		int k2=min(ry,Now.ry);
		if(k1>ly)Rec[++Rn]=(node){lx,rx,ly,k1,lz,rz};
		if(k2<ry)Rec[++Rn]=(node){lx,rx,k2,ry,lz,rz};
		Cut(lx,rx,k1,k2,lz,rz,3);
	}
	if(cmd==3)//z方向切割
	{
		int k1=max(lz,Now.lz);
		int k2=min(rz,Now.rz);
		if(k1>lz)Rec[++Rn]=(node){lx,rx,ly,ry,lz,k1};
		if(k2<rz)Rec[++Rn]=(node){lx,rx,ly,ry,k2,rz};
	}
}
inline int Query()
{
	int V=0;
	for(int i=1;i<=Rn;i++)V+=(Rec[i].rx-Rec[i].lx)*(Rec[i].ry-Rec[i].ly)*(Rec[i].rz-Rec[i].lz);
	return V;
} 
int main(){
	N=GetInt();
	int x,y,z,r;
	for(int i=1;i<=N;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		r=GetInt();
		Now=(node){x-r,x+r,y-r,y+r,z-r,z+r};
		Rt=Rn;
		for(int j=1;j<=Rt;j++)
		{
			if(Cross(Rec[j].lx,Rec[j].rx,Now.lx,Now.rx)&&Cross(Rec[j].ly,Rec[j].ry,Now.ly,Now.ry)&&Cross(Rec[j].lz,Rec[j].rz,Now.lz,Now.rz))
			{
			Cut(Rec[j].lx,Rec[j].rx,Rec[j].ly,Rec[j].ry,Rec[j].lz,Rec[j].rz,1);
			Rec[j]=Rec[Rt];
			Rec[Rt]=Rec[Rn];
			Rn--;Rt--;j--;
			}
		}
		Rec[++Rn]=Now; 
	}
	printf("%d",Query());
	return 0;
}