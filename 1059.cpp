/*
ID: baymax01
PROG: text
LANG: C++                  
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <cassert>
#include <cctype>
#include <queue>
#include <map>
using namespace std;
int main()
{
priority_queue<int, vector<int>, greater<int>>q;
int n,t1,t2,t3,ans=0;
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>t1;
	q.push(t1);
}
 while(1) {
            t2=q.top();
            q.pop();
            t3=q.top();
            q.pop();
            ans+=t2+t3;
            if(q.empty())break;
            q.push(t2+t3);
        }
cout<<ans;
	return 0;
}