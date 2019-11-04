#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 50010

using namespace std;

int n, big, small;
int a[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

priority_queue <int> pq;//greater heap

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
		pq.push(a[i]);
	while(pq.size() > 1)
	{
		int cur1 = pq.top();
		pq.pop();
		int cur2 = pq.top();
		pq.pop();
		pq.push(cur1 * cur2 + 1);
	}
	small = pq.top();
	pq.pop();
	for(rgi i = 1; i <= n; ++i)
		pq.push(-a[i]);
	while(pq.size() > 1)
	{
		int cur1 = -pq.top();
		pq.pop();
		int cur2 = -pq.top();
		pq.pop();
		pq.push(-(cur1 * cur2 + 1));
	}
	big = -pq.top();
	pq.pop();
	printf("%d", big - small);
	return 0;
}

