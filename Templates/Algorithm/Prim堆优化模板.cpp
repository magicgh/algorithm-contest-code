struct MST
{
	list<node>a[305];
	list<node>::iterator j;
	double dist[305];
	bool vst[305];
	inline void AddEdge(int x,int y,double z)
	{
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
		return;
	}
	inline bool Prim(int v0)
	{
	int cnt=0;
	priority_queue<heap>q;
	list<node>::iterator j;
	for(int i=1;i<=N;i++)dist[i]=INT_MAX;
	dist[v0]=0;q.push((heap){v0,0});
	while(!q.empty()&&cnt<=N)
	{
		heap now=q.top();
		q.pop();

		if(vst[now.num])continue;
		ans+=now.val;	
		vst[now.num]=1;
		cnt++;
		for(j=a[now.num].begin();j!=a[now.num].end();++j)
		{ 
			if(!vst[j->to]&&dist[j->to]>j->val)
			{
				dist[j->to]=j->val;
				q.push((heap){j->to,dist[j->to]});
			}
		}
	}
	if(cnt==N)return 1;
	else return 0;
	}
};
