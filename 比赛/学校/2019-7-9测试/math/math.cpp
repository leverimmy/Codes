#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn 200010

using namespace std;

const double k = 0.997;

ll n;
double ans = 0x3f3f3f3f3f3f3f3f;

struct node
{
	ll x, y;
} p[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	if(a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

double dis(ll a, ll b)
{
	return sqrt((double)(p[a].x - p[b].x) * (p[a].x - p[b].x) + (double)(p[a].y - p[b].y) * (p[a].y - p[b].y));
}

void solve1()
{
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = i + 1; j <= n; ++j)
			for(rgi k = j + 1; k <= n; ++k)
			{
				double cur = dis(i, j) + dis(j, k) + dis(k, i);
				ans = min(ans, cur);
			}
	printf("%.6lf", ans);
}

void SA()
{
	ll T = 5000;
	while(T > 1e-10)
	{
		ll cura = rand() % n + 1;
		ll curb = rand() % n + 1;
		ll curc = rand() % n + 1;
		while(curb == cura)
			curb = rand() % n + 1;
		while(curc == cura)
			curc = rand() % n + 1;
		double cur_ans = dis(cura, curb) + dis(curb, curc) + dis(curc, cura);
		double delta = cur_ans - ans;
		if(delta < 0)
			ans = cur_ans;
		else if(RAND_MAX * exp(-delta / T) > rand())
			ans = cur_ans;
		T *= k;
	}
}

void solve2()
{
	sort(p + 1, p + n + 1, cmp);
	srand(20040301);
	ans = dis(1, 2) + dis(2, 3) + dis(3, 1);
	for(rgi i = 1; i <= 888; ++i)
		SA();
	printf("%.6lf", ans);
}

int main()
{
//	freopen("math10.in", "r", stdin);
//	freopen("mmmmm.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].x = read();
		p[i].y = read();
	}
	if(n <= 400)
		solve1();
	else
		solve2();
	return 0;
}

