#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;
map<string,int>book;
int n;
int main() {
	ios::sync_with_stdio(false);
	char t;
	string book_name;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>t>>book_name;
	    if(t=='A')book[book_name]++;
	    if(t=='B'&&book[book_name])book[book_name]--;
	    if(t=='C')
	    {
	    	if(book[book_name]>=1)puts("yes");
	    	else puts("no");
	    }
	}
	return 0;
}