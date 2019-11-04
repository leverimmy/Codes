#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 5;

int n, a[N], num[N], ans;

struct Seg_Tree
{
	int lc, rc, val;
} t[N << 2];

//num[i] -> i上开了多少花 
//t[i].val -> [lc, rc]被线段覆盖的总次数 

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
		return;
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
}

void Add(int p, int l, int r)
{
	if(l == t[p].lc && t[p].rc == r)
	{
		t[p].val++;
		return;
	}
	int mid = t[p].lc + t[p].rc >> 1;
	if(r <= mid)
		Add(p << 1, l, r);
	else
	{
		if(l > mid)
			Add(p << 1 | 1, l, r);
		else
		{
			Add(p << 1, l, mid);
			Add(p << 1 | 1, mid + 1, r);
		}
	}
}

void Query(int p, int l, int r)
{
	ans += t[p].val;
	if(l == t[p].lc && t[p].rc == r)
		return;
	int mid = t[p].lc + t[p].rc >> 1;
	if(r <= mid)
		Query(p << 1, l, r);
	else
	{
		if(l > mid)
			Query(p << 1 | 1, l, r);
		else
		{
			Query(p << 1, l, mid);
			Query(p << 1 | 1, mid + 1, r);
		}
	}
}

int main()
{
	n = read();
	Build(1, 1, N);
	for(rgi i = 1; i <= n; ++i)
	{
		int l = read(), r = read();
		ans = 0;
		Query(1, l, l);
		int first = ans;//l点有多少线段覆盖 
		ans = 0;
		Query(1, r, r);
		int second = ans;//r点有多少线段覆盖 
		printf("%d\n", first + second - num[l] - num[r]);//减去已经开过花的次数 
		num[l] = first + 1;
		num[r] = second + 1;
		Add(1, l, r);
	}
	return 0;
}

