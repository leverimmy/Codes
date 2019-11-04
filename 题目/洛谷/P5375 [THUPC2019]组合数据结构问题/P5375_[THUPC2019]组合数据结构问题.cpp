#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

int n;
int stack_flag, queue_flag, less_heap_flag, greater_heap_flag;

struct stack
{
	ll siz;
	ll s[maxn];
	void push(ll val)
	{
		s[++siz] = val;
	}
	void pop()
	{
		siz--;
	}
	ll top()
	{
		return s[siz];
	}
	bool empty()
	{
		return siz == 0;
	}
} s;

struct queue
{
	ll head, tail;
	ll q[maxn];
	void push(ll val)
	{
		q[tail++] = val;
	}
	void pop()
	{
		head++;
	}
	ll front()
	{
		return q[head];
	}
	bool empty()
	{
		return tail == head;
	}
} q;

struct less_heap
{
	ll siz;
	ll lh[maxn];
	void push(ll val)
	{
		lh[++siz] = val;
		ll cur = siz;
		while(cur > 1)
		{
			if(lh[cur >> 1] > lh[cur])
				swap(lh[cur >> 1], lh[cur]);
			else
				break;
			cur >>= 1;
		}
	}
	void pop()
	{
		swap(lh[1], lh[siz--]);
		ll cur = 1;
		while((cur << 1) <= siz)
		{
			ll lc = cur << 1, rc = lc + 1, nxt;
			if(rc <= siz)
			{
				if(lh[lc] <= lh[rc])
					nxt = lc;
				else
					nxt = rc;
			}
			else
				nxt = lc;
			if(lh[nxt] < lh[cur])
				swap(lh[nxt], lh[cur]);
			else
				break;
			cur = nxt;
		}
	}
	ll top()
	{
		return lh[1];
	}
	bool empty()
	{
		return siz == 0;
	}
} lh, _gh;

struct greater_heap
{
	ll siz;
	ll gh[maxn];
	void push(ll val)
	{
		gh[++siz] = val;
		ll cur = siz;
		while(cur > 1)
		{
			if(gh[cur >> 1] < gh[cur])
				swap(gh[cur >> 1], gh[cur]);
			else
				break;
			cur >>= 1;
		}
	}
	void pop()
	{
		swap(gh[1], gh[siz--]);
		ll cur = 1;
		while((cur << 1) <= siz)
		{
			ll lc = cur << 1, rc = lc + 1, nxt;
			if(rc <= siz)
			{
				if(gh[lc] >= gh[rc])
					nxt = lc;
				else
					nxt = rc;
			}
			else
				nxt = rc;
			if(gh[nxt] > gh[cur])
				swap(gh[nxt], gh[cur]), cur = nxt;
			else
				break;
		}
	}
	ll top()
	{
		return gh[1];
	}
	bool empty()
	{
		return siz == 0;
	}
} gh;

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(ll x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	stack_flag = queue_flag = less_heap_flag = greater_heap_flag = 1;
	s.siz = lh.siz = gh.siz = _gh.siz = 0;
	q.head = q.tail = 0;
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		ll op = read(), val = read();
		if(op == 1)
		{
			if(stack_flag)
				s.push(val);
			if(queue_flag)
				q.push(val);
			if(less_heap_flag)
				lh.push(val);
			if(greater_heap_flag)
				gh.push(val);
		}
		else if(op == 2)
		{
			if(stack_flag)
			{
				if(s.empty())
					stack_flag = 0;
				else if(s.top() != val)
					stack_flag = 0;
				if(stack_flag)
					s.pop();
			}
			if(queue_flag)
			{
				if(q.empty())
					queue_flag = 0;
				else if(q.front() != val)
					queue_flag = 0;
				if(queue_flag)
					q.pop();
			}
			if(less_heap_flag)
			{
				if(lh.empty())
					less_heap_flag = 0;
				else if(lh.top() != val)
					less_heap_flag = 0;
				if(less_heap_flag)
					lh.pop();
			}
			if(greater_heap_flag)
			{
				if(gh.empty())
					greater_heap_flag = 0;
				else if(gh.top() != val)
					greater_heap_flag = 0;
				if(greater_heap_flag)
					gh.pop();
			}
		}
	}
	if(queue_flag)
		puts("Yes");
	else
		puts("No");
	if(stack_flag)
		puts("Yes");
	else
		puts("No");
	if(greater_heap_flag)
		puts("Yes");
	else
		puts("No");
	if(less_heap_flag)
		puts("Yes");
	else
		puts("No");
	return 0;
}

