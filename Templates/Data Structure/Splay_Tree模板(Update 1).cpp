inline void Rotate(int x,int &fa){
		int y=prt[x],z=prt[y],l=(ch[y][0]!=x),r=l^1;
		if(fa==y)fa=x;
		else ch[z][ch[z][1]==y]=x;
		prt[x]=z,prt[y]=x,prt[ch[x][r]]=y;
		ch[y][l]=ch[x][r],ch[x][r]=y;
		Maintain(y);Maintain(x);
	}
inline void Splay(int x,int &fa){
	while(x!=fa){
		if(prt[x]!=fa){
			if((ch[prt[x]][0]==x)^(ch[prt[prt[x]]][0]==prt[x]))Rotate(x,fa);
			else Rotate(prt[x],fa);//»√Œª“∆∂Ø
		}
		Rotate(x,fa); 
	}
}
