#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 100000 + 10;

int n, m;
int a[N];
ll s[N];

struct Seg_Tree
{
	int lc, rc;
	int add, val;
} t[N << 2];

int random(int l, int r)
{
	if(l == r)
		return l;
	return rand() * rand() % (r - l) + l;
}

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Update(int p)
{
	t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = a[l];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Update(p);
}

void Spread(int p)
{
	if(t[p].add != 0)
	{
		t[p << 1].add += t[p].add;
		t[p << 1 | 1].add += t[p].add;
		t[p << 1].val += t[p].add * (t[p << 1].rc - t[p << 1].lc + 1);
		t[p << 1 | 1].val += t[p].add * (t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1);
		t[p].add = 0;
	}
}

void Add(int p, int l, int r, int val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].add += val;
		t[p].val += val * (t[p].rc - t[p].lc + 1);
		return;
	}
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid)
		Add(p << 1, l, r, val);
	if(mid < r)
		Add(p << 1 | 1, l, r, val);
	Update(p);
}

int Query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	int res = 0;
	if(l <= mid)
		res += Query(p << 1, l, r);
	if(mid < r)
		res += Query(p << 1 | 1, l, r);
	return res;
}

int main()
{
	while(1)
	{
		srand(time(0));
		srand(rand());
		//Sleep(50);
		n = random(1, 100);
		cout << n << endl;
		for(rgi i = 1; i <= n; ++i)
			a[i] = a[i + n] = random(-1000, 1000);
		for(rgi i = 1; i <= n << 1; ++i)
			s[i] = s[i - 1] + a[i];
		//for(rgi i = 1; i <= n; ++i)
		//	cout << a[i] << " ";
		//puts("");
		Build(1, 1, n << 1);
		m = random(1, 100);
		cout << m << endl;
		for(rgi i = 1; i <= m; ++i)
		{
			int pos = random(1, n), val = random(-1000, 1000), std = -oo;
			ll cur_ans = -oo;
			//cout << pos << " " << val << endl;
			a[pos] = a[pos + n] = val;
			Add(1, pos, pos, val - Query(1, pos, pos));
			Add(1, pos + n, pos + n, val - Query(1, pos + n, pos + n));
			for(rgi l = 1; l <= n; ++l)
				for(rgi len = 1; len < n; ++len)
				{
					int r = l + len - 1;
					std = max(std, Query(1, l, r));
				}
			for(rgi i = 1; i <= n << 1; ++i)
				s[i] = s[i - 1] + a[i];
			for(rgi l = 1; l <= n; ++l)
				for(rgi len = 1; len < n; ++len)
				{
					int r = l + len - 1;
					cur_ans = max(cur_ans, s[r] - s[l - 1]);
				}
			//cout << cur_ans << " " << std << endl;
			if(cur_ans != std)
			{
				cout << "fuck!";
				return 0;
			}
		}
		n = m = 0;
		memset(a, 0, sizeof(a));
		memset(t, 0, sizeof(t));
		memset(s, 0, sizeof(s));
	}
	return 0;
}

