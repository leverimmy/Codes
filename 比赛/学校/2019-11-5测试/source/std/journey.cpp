#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAXN 100005
typedef long long ll;

ll max(ll a, ll b) { return a > b ? a : b; }

ll n, m, num, u, v, t1, p, k, x, maxt;
ll ex[MAXN], a[MAXN], b[MAXN], t[MAXN], la, lb;
bool get;

ll read()
{
	ll o = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9')  o = o * 10 + ch - '0', ch = getchar();
	return o;
}

void init()
{
	memset(ex, 0, sizeof(ex)), get = 0;
	n = read(), m = read();
	for (int i = 1; i <= m; i++) 
	{
		num = read(), u = read(), v = read(), t1 = read();
		a[num - 1] = u, t[num] = t1;
		if (num == m) a[m] = v;
	}
	for (int i = 1; i <= m; i++) t[i] += t[i - 1];
	p = read();
	for (int i = 0; i <= p - 1; i++) k = read(), b[i] = k;
	maxt = read();
	la = m + 1, lb = p;
}

int main()
{
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
	scanf("%d", &x);
	while (x--)
	{
    	init();
		for (int j = 0; j < la && j < lb && b[j] == a[j]; ex[0] = ++j); 
		for (int i = 0; i <= la - 1; i++)
		{
			if (i)
			{
				ll len = i + ex[i - 1] - 2;
	 			for (ll x = max(0, len - i + 1); i + x < la && x < lb && a[i + x] == b[x]; ex[i] = ++x);
			}
	 		if (ex[i] == lb)
			{
				if (t[i + lb - 1] <= maxt) printf("YES %I64d\n", t[i + lb - 1]), get = 1;
                break;
			}
	 	}
	 	if (!get) printf("NO\n");
	}
	return 0;
}
