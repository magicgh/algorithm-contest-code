#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const char ok[]="YES";
const char no[]="NO";
int N,Vlen=0,len=0,T;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Vector
{
	double x,y;
	Vector(double x=0,double y=0):x(x),y(y){};
	inline double CrossMulti/*this A*/(Vector &a){return this->x*a.y-a.x*this->y;}
	inline double Cross/*AB-AC*/(Vector &a,Vector &b,Vector &c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
	inline double LineLen/*this A*/(Vector &a){return sqrt(double(this->x-a.x)*(this->x-a.x)+(this->y-a.y)*(this->y-a.y));}
	inline bool OnLine/*this A,B*/(Vector &a,Vector &b){return ((a.x-this->x)*(a.y-b.y)-(a.x-b.x)*(a.y-this->y)==0)?1:0;}
	inline bool IsLineCross/*AB,CD*/(Vector a,Vector b,Vector c,Vector d){return (Cross(a,c,d)*Cross(b,c,d)<0)&&(Cross(c,a,b)*Cross(d,a,b)<0);}
};
Vector TODO,a[1005],b[1005],vec[1005];
inline void AddCross(Vector a,Vector b,Vector c,Vector d);
inline void HPI(Vector now,Vector next)
{
	a[N+1]=a[1];
	len=0;
	for(int i=2;i<=N+1;i++)
	{
		if(TODO.Cross(now,a[i-1],next)>=0)
		{
			b[++len]=a[i-1];
			if(TODO.Cross(now,a[i],next)<=0)AddCross(a[i-1],a[i],now,next);
		}
		else if(TODO.Cross(now,a[i],next)>0)AddCross(a[i-1],a[i],now,next);
		}
		for(int i=1;i<=len;i++)a[i]=b[i];
		N=len;
	}
inline void AddCross(Vector a,Vector b,Vector c,Vector d)
{
	double c1=TODO.Cross(a,d,b),c2=TODO.Cross(a,c,b);
	::b[++len].x=(c1*c.x-c2*d.x)/(c1-c2);
	::b[len].y=(c1*c.y-c2*d.y)/(c1-c2);
}
inline void Area()
{
	double ans=0;
	a[N+1]=a[1];
	for(int i=1;i<=N;i++)ans+=a[i].CrossMulti(a[i+1]);
	printf("%s\n",len==0?no:ok);
}
inline void Init()
{
	Vector next,now,last;
	now=vec[1];last=now;
	for(int i=2;i<=Vlen;i++)
	{	
		next=vec[i];
		HPI(now,next);
		now=next;	
	}
	HPI(now,last);
}
int main(){
	T=GetInt();
	for(int i=1;i<=T;i++)
	{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(vec,0,sizeof(vec));
	len=0,Vlen=0;
	N=GetInt();
	for(int i=1;i<=N;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	memcpy(vec,a,sizeof(a));
	Vlen=N;
	Init();
	Area();	
	
}
	return 0;
}