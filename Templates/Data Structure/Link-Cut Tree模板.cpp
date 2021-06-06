struct LCT{
	int prt[MAXN],ch[MAXN][2];
	bool aux[MAXN],rev[MAXN];
	inline void Pushdown(int x){
		if(rev[x]){
			swap(ch[x][0],ch[x][1]);
			rev[ch[x][0]]^=1,rev[ch[x][1]]^=1,rev[x]=0;
		}
	}
	inline void Rotate(int x){
		int y=prt[x],z=prt[y],l=(ch[y][0]!=x),r=l^1;
		if(aux[y])ch[z][!(ch[z][0]==y)]=x;
		else aux[y]=1,aux[x]=0;
		prt[x]=z,prt[y]=x,prt[ch[x][r]]=y;
		ch[y][l]=ch[x][r],ch[x][r]=y;
	}
	inline void Splay(int x){
		Pushdown(x);
		while(aux[x]){
			int y=prt[x],z=prt[y];
			if(aux[y])Pushdown(z);
			Pushdown(y);Pushdown(x);
			if(aux[y]){if(ch[y][0]==x^ch[z][0]==y)Rotate(x);else Rotate(y);}
			Rotate(x);
		}
	}
	inline void Access(int x,int y){
		if(!x)return;
		Splay(x);
		aux[ch[x][1]]=0;
		prt[y]=x;ch[x][1]=y;aux[y]=1;
		Access(prt[x],x); 
	}
	inline void Reverse(int x){
		Access(x,0);
		Splay(x);
		rev[x]^=1;
	}
	inline void Cut(int x,int y){
		Reverse(x);
		Access(y,0);
		Splay(y);
		ch[y][0]=aux[ch[y][0]]=prt[ch[y][0]]=0;
	} 
	inline void Link(int x,int y){
		Reverse(x);
		prt[x]=y; 
	}
	inline int Findroot(int x){
		Access(x,0);
		Splay(x);
		while(ch[x][0])
		{
			x=ch[x][0];
			Pushdown(x); 
		}
		return x;
	} 
};
