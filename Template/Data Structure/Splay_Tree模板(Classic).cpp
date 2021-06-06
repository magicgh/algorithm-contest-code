struct splay_tree
{
	int data[MAXN],prt[MAXN],l[MAXN],r[MAXN],ln[MAXN],rn[MAXN];
	int root,cnt;
	splay_tree()
	{
		root=0,cnt=0;
		memset(data,0,sizeof(data));
		memset(prt,0,sizeof(prt));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(ln,0,sizeof(ln));
		memset(rn,0,sizeof(rn));
	}
		inline void DFS(int u)
	{
		if(l[u]>0)DFS(l[u]);
		cout<<u<<"::"<<data[u]<<"->";
		if(r[u]>0)DFS(r[u]);
	}
	inline int NodeNum(int x)//����x�ڵ��µĽڵ���
	{
		return ln[x]+rn[x]+1;
	}
inline void Zig(int x)//���� 
	{
		int y=prt[x];
		l[y]=r[x];
		if(r[x])prt[r[x]]=y;
		prt[x]=prt[y];
		if(prt[y])
		{
			if(l[prt[y]]==y)l[prt[y]]=x;
			else r[prt[y]]=x;
		}
		prt[y]=x;r[x]=y;
		ln[y]=rn[x];rn[x]=NodeNum(y);
	}
	inline void Zag(int x)//���� 
	{
		int y=prt[x];
		r[y]=l[x];
		if(l[x])prt[l[x]]=y;
		prt[x]=prt[y];
		if(prt[y])
		{
			if(l[prt[y]]==y)l[prt[y]]=x;
			else r[prt[y]]=x;
		}
		prt[y]=x;l[x]=y;
		rn[y]=ln[x];ln[x]=NodeNum(y);
	}
	inline void Splay(int x)//��չ
	{
		while(prt[x])
		{
			int u=prt[x];
			if(prt[u]==0)
			{
				if(x==l[u])Zig(x);
				else Zag(x);
				break;
			}
			if(x==l[u])
			{
				if(u==l[prt[u]])Zig(u),Zig(x);
				else Zig(x),Zag(x);
			}
			if(x==r[u])
			{
				if(u==l[prt[u]])Zag(x),Zig(x);
				else Zag(u),Zag(x);
			}
		}
		root=x;
	}
	inline bool Find(int x)//����Ԫ�� 
	{
		int u=root;
		while(u)
		{
			if(x==data[u]){Splay(u);return 1;}//��ת�����ڵ� 
			if(x<data[u])u=l[u];
			else u=r[u];		
		}
		return 0;//Not Found 
	}
	inline void Insert(int x)//���� 
	{
		int u=root,getfa=0;
		while(u)
		{
			getfa=u;
			if(x<=data[u])ln[u]++,u=l[u];
			else rn[u]++,u=r[u];
		}
		data[++cnt]=x;l[cnt]=0;r[cnt]=0;ln[cnt]=0;rn[cnt]=0;prt[cnt]=0;
		if(root==0){root=cnt;return;}//����
		prt[cnt]=getfa;
		if(x<=data[getfa])l[getfa]=cnt;
		else r[getfa]=cnt;
		Splay(cnt);
	}
inline void Delete(int x)//ɾ��
	{
		Find(x);//����x 
		int u=root;
		int lch=l[u],rch=r[u];
		if(!lch&&!rch){root=0;return;}//����������
		if(!lch)//��������
		{root=rch;prt[rch]=0;return;}
		if(!rch)//��������			
		{root=lch;prt[lch]=0;return;}
		//������������
		u=lch;//����������ʼ
		prt[lch]=0;
		while(r[u])u=r[u];//Ѱ��x�ڵ��ǰ��
		Splay(u);
		r[u]=rch;prt[rch]=u;
		rn[u]=NodeNum(rch);
	}
	inline int FindOrder(int k)//���ҵ�K�� 
	{
		int u=root;
		if(NodeNum(u)<k)return -1;
		while(true)
		{
			if(rn[u]+1==k)return data[u];
			if(rn[u]>=k)u=r[u];//�Ҷ���Ѱ��
			else //�����Ѱ��
			{
				k=k-rn[u]-1;//ln[x]+rn[x]+1=NodeNum(x) 
				u=l[u];
			} 
		}
	}
	inline int LowerBound(int x)//ǰ��
	{
		Find(x);//����x 
		int u=l[root];//��xС(��) 
		while(u)//�����(��) 
		{
		if(!r[u])break;//�ѵ�Ҷ�ӽڵ� 
		u=r[u];
		}
		if(u)return data[u];
		return -1;//Not Found
	}
	inline int UpperBound(int x)//����
	{
		Find(x);//����x 
		int u=r[root];//��x��(��)
		while(u)//����С(��) 
		{
		if(!l[u])break;//�ѵ�Ҷ�ӽڵ� 
		u=l[u];
		}
		if(u)return data[u];
		return -1;//Not Found
		
	}
	inline int Max()
	{	
		int u=root;
		while(r[u])u=r[u];//���ֵ������
		return data[u]; 
	}
	inline int Min()
	{
		int u=root;
		while(l[u])u=l[u];//���ֵ������
		return data[u];
	}
};
