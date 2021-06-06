struct treap
{
	int data[MAXN],pro[MAXN],ch[MAXN][2],s[MAXN][2];
	int cnt,root;
	treap()
	{
		cnt=0;root=0;
	}
	inline int Getrand(){return rand()%MAXN+1;}
	inline int NodeNum(int x){return s[x][0]+s[x][1]+1;}
	inline void Rotate(int &x,int cmd)
	{
		int y=ch[x][cmd];
		ch[x][cmd]=ch[y][!cmd];
		ch[y][!cmd]=x;
		s[x][cmd]=s[y][!cmd];
		s[y][!cmd]=NodeNum(x);
		x=y;
	}
	inline void Insert(int &u,int x)
	{
		if(u==0)//叶子节点 
		{
			u=++cnt;
			data[u]=x;
			ch[u][0]=ch[u][1]=s[u][0]=s[u][1]=0;
			pro[u]=Getrand();
			return;
		}
		else
		{	
			bool cmd=x>data[u];
			Insert(ch[u][cmd],x);
			s[u][cmd]++;
			if(pro[ch[u][cmd]]<pro[u])Rotate(u,cmd);//维护小根堆 
		}
	}
	inline void Erase(int &u,int x)
	{
		if(u==0)return;
		if(x==data[u])
		{
			if(!ch[u][0]&&!ch[u][1]){u=0;return;}//为叶子节点
			int lpro=0x7fffffff,rpro=0x7fffffff;
			if(ch[u][0])lpro=pro[ch[u][0]];
			if(ch[u][1])rpro=pro[ch[u][1]];
			bool cmd=lpro>rpro;
			Rotate(u,cmd);s[u][!cmd]--;Erase(ch[u][!cmd],x);
		}
		else s[u][x>data[u]]--,Erase(ch[u][x>data[u]],x);
	}
	inline bool Find(int u,int x)
	{
		if(u==0)return 0;
		if(x==data[u])return 1;
		else return Find(ch[u][x>data[u]],x);
	}
	inline int FindOrder(int u,int k)
	{
		if(NodeNum(u)<k)return -1;
		if(s[u][0]+1==k)return data[u];
		if(k<=s[u][0])return FindOrder(ch[u][0],k);
		else return FindOrder(ch[u][1],k-s[u][0]-1);
	}
};
