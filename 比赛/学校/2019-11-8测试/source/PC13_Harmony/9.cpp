#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <string> 
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
#define NO 1000005
#define MO 100005
#define fi first
#define se second
#define lln putchar('\n')
#define blk putchar(' ')
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
	return last == '-' ? -ret : ret;
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
// head

int Q;
priority_queue<int> q;
// variable

void init()
{
	if (scanf("%lld", &Q) == -1)
		exit(0);
	while (Q--)
	{
		int ty = read();
		if (ty == 1)
			q.push(read());
		else
			write(q.empty() ? -1 : q.top()), lln, q.pop();
	}
}
//functions

int main()
{
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	while (1)
		init();
	return 0;
}
//main
/*

*/
