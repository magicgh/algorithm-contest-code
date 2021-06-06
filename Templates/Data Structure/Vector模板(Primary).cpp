struct Vector
{
	int x,y;
	Vector(int x=0,int y=0):x(x),y(y){};
	inline Vector operator +(Vector &a){return Vector(a.x+this->x,a.y+this->y);}
	inline Vector operator -(Vector &a){return Vector(a.x-this->x,a.y-this->y);}
	inline Vector operator *(int num){return Vector(this->x*num,this->y*num);}
	inline Vector operator /(int num){return Vector(this->x/num,this->y/num);}
	inline int DotMulti/*this A*/(Vector &a){return this->x*a.x+this->y*a.y;}
	inline int CrossMulti/*this A*/(Vector &a){return this->x*a.y-a.x*this->y;}
	inline int Cross/*AB-AC*/(Vector &a,Vector &b,Vector &c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
	inline double LineLen/*this A*/(Vector &a){return sqrt(double(this->x-a.x)*(this->x-a.x)+(this->y-a.y)*(this->y-a.y));}
	inline bool OnLine/*this A,B*/(Vector &a,Vector &b){return ((a.x-this->x)*(a.y-b.y)-(a.x-b.x)*(a.y-this->y)==0)?1:0;}
	inline bool OnSegment/*this A,B*/(Vector &a,Vector &b)
	{
		return (((a.x-this->x)*(a.y-b.y)-(a.x-b.x)*(a.y-this->y)==0)&&this->x>=min(a.x,b.x)&&this->x<=max(a.x,b.x)&&this->y>=min(a.y,b.y)&&this->y<=max(a.y,b.y))?1:0;
	}
	inline bool IsLineCross/*AB,CD*/(Vector &a,Vector &b,Vector &c,Vector &d){return (Cross(a,c,d)*Cross(b,c,d)<0)&&(Cross(c,a,b)*Cross(d,a,b)<0);}
	inline void ConvexHullArea(Vector a[],int b[])
	{
		double squ=0,len=0;
		b[++b[0]]=b[1];
		for(int i=2;i<=b[0];i++)
		{
		squ+=Cross(a[1],a[b[i-1]],a[b[i]]);
		len+=a[b[i]].LineLen(a[b[i-1]]);
		}
		printf("%.2lf\n%.2lf",squ==0?len/2:len,abs(squ)/2);	
	}
	inline void GrahamScan(Vector a[],int b[])
	{
		int s[105]={0,1,2},top=2;
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
