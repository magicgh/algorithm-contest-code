#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>	
using namespace std;
const double PI=3.14159265358979323846264338327950288419716939937510;
int N;
double L;
double CirLen=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Vector
{
	double x,y;
	Vector(int x=0,int y=0):x(x),y(y){};
	inline Vector operator +(Vector &a){return Vector(a.x+this->x,a.y+this->y);}
	inline Vector operator -(Vector &a){return Vector(a.x-this->x,a.y-this->y);}
	inline Vector operator *(int num){return Vector(this->x*num,this->y*num);}
	inline Vector operator /(int num){return Vector(this->x/num,this->y/num);}
	inline double DotMulti/*this A*/(Vector &a){return this->x*a.x+this->y*a.y;}
	inline double CrossMulti/*this A*/(Vector &a){return this->x*a.y-a.x*this->y;}
	inline double Cross/*AB-AC*/(Vector &a,Vector &b,Vector &c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
	inline double LineLen/*this A*/(Vector &a){return sqrt(double(this->x-a.x)*(this->x-a.x)+(this->y-a.y)*(this->y-a.y));}
	inline double OnLine/*this A,B*/(Vector &a,Vector &b){return ((a.x-this->x)*(a.y-b.y)-(a.x-b.x)*(a.y-this->y)==0)?1:0;}
	inline double OnSegment/*this A,B*/(Vector &a,Vector &b)
	{	
		return (((a.x-this->x)*(a.y-b.y)-(a.x-b.x)*(a.y-this->y)==0)&&this->x>=min(a.x,b.x)&&this->x<=max(a.x,b.x)&&this->y>=min(a.y,b.y)&&this->y<=max(a.y,b.y))?1:0;
	}
	inline bool IsLineCross/*AB,CD*/(Vector &a,Vector &b,Vector &c,Vector &d){return (Cross(a,c,d)*Cross(b,c,d)<0)&&(Cross(c,a,b)*Cross(d,a,b)<0);}
	inline void ConvexHullArea(Vector a[],int b[])
	{
		double len=0,squ=0;
		b[++b[0]]=b[1];
		for(int i=2;i<=b[0];i++)
		{
		len+=a[b[i]].LineLen(a[b[i-1]]);
		}
		printf("%.2lf",len+CirLen);	
	}
	inline void GrahamScan(Vector a[],int b[])
	{
		int s[10005]={0,1,2};int top=2;
		for(int i=3;i<=N;i++)
		{
		while(top>1&&Cross(a[s[top-1]],a[s[top]],a[i])<=0)top--;
		s[++top]=i;
		}
		for(int i=1;i<=top;i++)b[++b[0]]=s[i];
		memset(s,0,sizeof(s));
		s[1]=N,s[2]=N-1,top=2;
		for(int i=N-2;i>=1;i--)
		{
		while(top>1&&Cross(a[s[top-1]],a[s[top]],a[i])<=0)top--;
		s[++top]=i;
		}
		for(int i=2;i<top;i++)b[++b[0]]=s[i];
		ConvexHullArea(a,b);
	}
};
Vector vec[10005],TODO;int b[10005];
bool cmp(Vector x,Vector y)
{
	return x.y<y.y||(x.y==y.y&&x.x<y.x);
}
int main(){
	N=GetInt();scanf("%lf",&L);
	CirLen=PI*2*L;
	for(int i=1;i<=N;i++)scanf("%lf%lf",&vec[i].x,&vec[i].y);
	sort(vec+1,vec+N+1,cmp);
	TODO.GrahamScan(vec,b);	
	return 0;
}