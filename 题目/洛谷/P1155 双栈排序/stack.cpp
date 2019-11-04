#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline
#define out(ch) putchar(ch), putchar(' ');

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;
const int M = 1000 + 10;

int n, cur_val = 1, cnt, ok;
int a[N], f[N];
int first[N], color[N];
// color[i] -> 0 : the first stack; 1 the second stack

struct edge
{
	int to, _next; 
} e[M << 1];

struct STACK
{
	static const int MAX_SIZE = 2e5;
	int stk[MAX_SIZE + 10];
	int _top;
	STACK()
	{
		_top = 0; 
	}
	void push(int val)
	{
		if(_top >= MAX_SIZE)
		{
			puts("Overflow!");
			exit(0);
		}
		stk[++_top] = val;
	}
	void pop(){_top--;}
	void clear(){_top = 0;}
	int top(){return stk[_top];}
	bool empty(){return _top == 0;}
}s[2];

struct QUEUE
{
	static const int MAX_SIZE = 2e5;
	int que[MAX_SIZE + 10];
	int _head, _tail;
	QUEUE() 
	{
		_head = _tail = 0;
	}
	void push(int val){que[++_tail] = val;}
	void pop(){_head++;}
	void clear(){_head = _tail = 0;}
	int front(){return que[_head + 1];}
	int back(){return que[_tail];}
	bool empty(){return _tail == _head;}
};

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

bool OK_POP(int id)//id = 0 -> the first stack; id = 1 -> the second stack
{
	if(!s[id].empty() && s[id].top() == cur_val)
	{
		out(id ? 'd' : 'b');
		s[id].pop();
		cur_val++;
		return 1;
	}
	return 0;
}

void PUSH(int id, int val)
{
	if(id == 1)
		while(OK_POP(0));	
	while(!s[id].empty() && s[id].top() < val)
		if(!OK_POP(id))
			OK_POP(id ^ 1);
	if(id == 1)
		while(OK_POP(0));
	s[id].push(val);
	out(id ? 'c' : 'a');
}

int main()
{
	n = read();
	memset(first, -1, sizeof(first));
	memset(color, -1, sizeof(color));
	for(rgi i = 1; i <= n; ++i)
		f[i] = a[i] = read();
	for(rgi i = n - 1; i >= 1; --i)
		f[i] = min(a[i], f[i + 1]);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = i + 1; j <= n; ++j)
			if(f[j] < a[i] && a[i] < a[j])
			{
				Add_Edge(i, j);
				Add_Edge(j, i);
			}
	for(rgi i = 1; i <= n; ++i)
		if(color[i] == -1)
		{
			struct QUEUE q;
			q.clear();
			q.push(i), color[i] = 0;
			while(!q.empty())
			{
				int x = q.front();
				q.pop();
				for(rgi j = first[x]; ~j; j = e[j]._next)
				{
					int y = e[j].to;
					if(color[y] != -1 && color[y] != (color[x] ^ 1))
					{
						puts("0");
						return 0;
					}
					if(color[y] == -1)
						q.push(y);
					color[y] = color[x] ^ 1;
				}
			}
		}
	for(rgi i = 1; i <= n; ++i)
		PUSH(color[i], a[i]);
	while(!ok)
	{
		ok = 1;
		while(OK_POP(0))
			ok = 0;
		while(OK_POP(1))
			ok = 0;
	}
	return 0;
}

