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
