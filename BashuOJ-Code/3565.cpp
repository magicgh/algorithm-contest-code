#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
queue<int>q;
char t;
int main(){
	while(cin>>t)
	{
		if(t=='O')
		{
			if(q.empty())puts("None");
			else printf("%d\n",q.front()),q.pop();
		}
		if(t=='I')
		{
			int x;
			scanf("%d",&x);
			q.push(x);
		}
	}
	return 0;
}
