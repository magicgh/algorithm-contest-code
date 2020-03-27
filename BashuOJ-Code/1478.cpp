#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>	
using namespace std;
int N,s[105],top,b[105];
double l=0,ans=0;
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
	int x,y;
	Vector(int x=0,int y=0):x(x),y(y){};
	inline Vector operator +(Vector &a){return Vector(a.x+this->x,a.y+this->y);}
	inline Vector operator -(Vector &a){return Vector(a.x-this->x,a.y-this->y);}
	inline Vector operator *(int num){return Vector(this->x*num,this->y*num);}
	inline Vector operator /(int num){return Vector(this->x/num,this->y/num);}
	inline int DotMulti(Vector &a,Vector &b){return a.x*b.x+a.y*b.y;}
	inline int CrossMulti(Vector &a,Vector &b){return a.x*b.y-b.x*a.y;}
	inline int Cross/*AB-AC*/(Vector &a,Vector &b,Vector &c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
	inline double LineLen(Vector &a,Vector &b){return sqrt(double(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
	inline bool OnLine/*a B,C*/(Vector &a,Vector &b,Vector &c){return ((b.x-a.x)*(b.y-c.y)-(b.x-c.x)*(b.y-a.y)==0)?1:0;}
	inline bool OnSegment/*a B,C*/(Vector &a,Vector &b,Vector &c)
	{
		return (((b.x-a.x)*(b.y-c.y)-(b.x-c.x)*(b.y-a.y)==0)&&a.x>=min(b.x,c.x)&&a.x<=max(b.x,c.x)&&a.y>=min(b.y,c.y)&&a.y<=max(b.y,c.y))?1:0;
	}
	inline bool IsLineCross/*AB,CD*/(Vector &a,Vector &b,Vector &c,Vector &d){return (Cross(a,c,d)*Cross(b,c,d)<0)&&(Cross(c,a,b)*Cross(d,a,b)<0);}
};
Vector vec[15],TODO;
bool cmp(Vector x,Vector y)
{
	return x.y<y.y||(x.y==y.y&&x.x<y.x);
}
void Graham_Scan()
{
	s[1]=1,s[2]=2,top=2;
	for(int i=3;i<=N;i++)
	{
		while(top>1&&TODO.Cross(vec[s[top-1]],vec[s[top]],vec[i])<=0)top--;
		s[++top]=i;
	}
	for(int i=1;i<=top;i++)b[++b[0]]=s[i];
	memset(s,0,sizeof(s));
	s[1]=N,s[2]=N-1,top=2;
	for(int i=N-2;i>=1;i--)
	{
		while(top>1&&TODO.Cross(vec[s[top-1]],vec[s[top]],vec[i])<=0)top--;
		s[++top]=i;
	}
	for(int i=2;i<top;i++)b[++b[0]]=s[i];
}
void Area()
{
	b[++b[0]]=b[1];
	for(int i=2;i<=b[0];i++)
	{
		ans+=TODO.Cross(vec[1],vec[b[i-1]],vec[b[i]]);
		l+=TODO.LineLen(vec[b[i]],vec[b[i-1]]);
	}
	printf("%.2lf\n%.2lf",ans==0?l/2:l,abs(ans)/2);	
}
int main(){
	N=GetInt();	
	for(int i=1;i<=N;i++)vec[i].x=GetInt(),vec[i].y=GetInt();
	if(N==2)printf("%.2lf\n%.2lf",TODO.LineLen(vec[1],vec[2]),0.00);
	else
	{
	sort(vec+1,vec+N+1,cmp);
	Graham_Scan();
	Area();
	}
	return 0;
}
