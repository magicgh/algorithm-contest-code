#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
int N,cnt=0,Rn=0;
double Area=0;
struct node
{
	double lx,ly,rx,ry;
};
node Rec[1005];
inline void Cut(int v,double ax,double ay,double bx,double by,int cmd)
{
	
	if(cmd==1)//x方向的切割 
	{
		double k1=max(ax,Rec[v].lx);
		double k2=min(bx,Rec[v].rx);
		if(k1>Rec[v].lx)Rec[++Rn]=((node){Rec[v].lx,Rec[v].ly,k1,Rec[v].ry});
		if(k2<Rec[v].rx)Rec[++Rn]=((node){k2,Rec[v].ly,Rec[v].rx,Rec[v].ry});
		Cut(v,k1,ay,k2,by,2);		
	}
	if(cmd==2)//y方向切割
	{
		double k1=max(ay,Rec[v].ly);
		double k2=min(by,Rec[v].ry);
		if(k1>Rec[v].ly)Rec[++Rn]=((node){ax,Rec[v].ly,bx,k1});
		if(k2<Rec[v].ry)Rec[++Rn]=((node){ax,k2,bx,Rec[v].ry});
	} 
}	 
int main(){
	double ax,ay,bx,by;
	while(~scanf("%d",&N),N!=0)
	{
		memset(Rec,0,sizeof(Rec));
		Area=0;
		Rn=0; 
		for(int i=1;i<=N;i++)
		{
			scanf("%lf%lf%lf%lf",&ax,&ay,&bx,&by);
			for(int j=0;j<=Rn;j++)
			{
				if(Rec[j].lx>=bx||Rec[j].ly>=by||Rec[j].rx<=ax||Rec[j].ry<=ay)continue;
				Cut(j,ax,ay,bx,by,1);
				Rec[j]=Rec[Rn];
				Rn--;
				j--;
			}
			Rec[++Rn]=((node){ax,ay,bx,by});
		}
		for(int i=1;i<=Rn;i++)Area+=(Rec[i].rx-Rec[i].lx)*(Rec[i].ry-Rec[i].ly);	 
		printf("Test case #%d\n",++cnt);
		printf("Total explored area: %.2lf\n\n",Area);
	}
	return 0;
}
