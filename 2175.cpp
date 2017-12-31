#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
double a[1005], s, ans = 0, tot, cnt;
int n;
inline int getint()
{
	int num = 0, bj = 1;
	char c = getchar();
	while (c < '0' || c > '9')bj = (c == '-' || bj == -1) ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num * bj;
}
int main()
{
	n = getint(); tot = n * (n - 1) / 2;
	for (ri i = 1; i <= n; i++)scanf("%lf", &a[i]);
	scanf("%lf", &s);
	for (ri i = 1; i < n; i++)
	{	
		if (s < a[i])continue;
		int num = s / a[i];
		for (ri j = i + 1; j <= n; j++)
			ans = max(ans, num * (a[j] - a[i]));
	}
	for (ri i = 1; i < n; i++)
		if (s >= a[i])
			for (ri j = i + 1; j <= n; j++)if (a[j] > a[i])cnt++;
	printf("%.3lf\n%.3lf", ans, cnt / tot);
	return 0;
}
