inline void Topsort()
{
	for(ri i=1;i<=n;i++)if(!Deg[i])q.push(i);
	while(!q.empty())
	{
		int x=q.top();q.pop();
		ans[++ans[0]]=x;
		vector<int>::iterator it;
		for(it=a[x].begin();it!=a[x].end();++it)
		{
			Deg[*it]--;
			if(!Deg[*it])q.push(*it);
		}
	}
}
