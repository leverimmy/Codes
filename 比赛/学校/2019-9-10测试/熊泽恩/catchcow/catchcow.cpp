#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 2e5 + 10;

int n, k, cnt;
int ans[N << 1], vis[N << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct QUEUE
{
	static const int MAX_SIZE = 4e6;
	int _head, _tail, que[MAX_SIZE + 10];
	void clear(){_head = _tail = 0;}
	void push(int val){que[++_tail] = val;}
	void pop(){(_head + 1 == _tail) ? (_head = _tail = 0) : (_head++);}
	int front(){return que[_head + 1];}
	int back(){return que[_tail];}
	int size(){return _tail - _head;}
	bool empty(){return _head == _tail;}
	QUEUE(){clear();}
} q;

void bfs()
{
	q.push(n), vis[n] = 1, ans[n] = 0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		if(x == k)
		{
			printf("%d", ans[k]);
			return;
		}
		if(!vis[x + 1])
			q.push(x + 1), ans[x + 1] = ans[x] + 1, vis[x + 1] = 1;
		if(!vis[x - 1] && x > 0)
			q.push(x - 1), ans[x - 1] = ans[x] + 1, vis[x - 1] = 1;
		if(!vis[x * 2] && x <= k)
			q.push(x * 2), ans[x * 2] = ans[x] + 1, vis[x * 2] = 1;
	}
}

int main()
{
//	freopen("catchcow.in", "r", stdin);
//	freopen("catchcow.out", "w", stdout);
	n = read(), k = read();
	bfs();
	return 0;
}
/*
5 17

0 100000

*/
